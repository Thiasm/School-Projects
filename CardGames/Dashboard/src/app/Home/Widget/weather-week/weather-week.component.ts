import { MatDialog } from '@angular/material/dialog';
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { DialogWeatherComponent } from './../../../Dialog/dialog-weather/dialog-weather.component';

@Component({
  selector: 'app-weather-week',
  templateUrl: './weather-week.component.html',
  styleUrls: ['./weather-week.component.scss']
})
export class WeatherWeekComponent implements OnInit {

  @Input() id: number;
  @Output() removeComponent = new EventEmitter<number>();

  input: string;
  city: string;

  List: Array<{date: string, sky: string, temperature: number}> = [];

  constructor(public dialog: MatDialog, private http: HttpClient) {
  }

  async ngOnInit() {
    this.input = '';
    this.city = '';
    await this.openDialog();
    this.callApi();
  }

    callApi(): void {
      const optionRequete = {
        headers: new HttpHeaders({
          'Access-Control-Allow-Origin': '*',
           city: this.city
        })
      };

      this.http.get<any>('http://localhost:8080/weatherweek', optionRequete).subscribe({
        next: data => {
          this.List = [];
          data.weather.forEach((element: any) => {
            element.date = element.date.substring(5);
            element.date = element.date.split(' ', 1);
            this.List.push(element);
          });
        },
        error: error => {
          this.List = [];
          console.log('Error');
          this.city = 'City not found';
        }
      });
    }

    removeWidget(): void {
    this.removeComponent.emit(this.id);
  }

  reloadWidget(): void {
    console.log('reload');
    this.callApi();
  }

  async openDialog() {
    const dialogRef = this.dialog.open(DialogWeatherComponent, {
      data: {city: this.input}
    });

    dialogRef.afterClosed().subscribe(result => {
      this.city = result;
      if (result === '') {
        this.city = 'City not found';
      }
      this.input = '';
      this.callApi();
    });
  }
}
