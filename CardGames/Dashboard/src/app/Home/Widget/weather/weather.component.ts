import { MatDialog } from '@angular/material/dialog';
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { DialogWeatherComponent } from './../../../Dialog/dialog-weather/dialog-weather.component';

@Component({
  selector: 'app-weather',
  templateUrl: './weather.component.html',
  styleUrls: ['./weather.component.scss']
})
export class WeatherComponent implements OnInit {

  @Input() id: number;
  @Output() removeComponent = new EventEmitter<number>();

  input: string;
  temperature: number;
  sky: string;
  city: string;

  constructor(public dialog: MatDialog, private http: HttpClient) {
  }

  async ngOnInit() {
    this.input = '';
    this.city = 'Select a City';
    this.sky = 'none';
    this.temperature = 0;
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

      this.http.get<any>('http://localhost:8080/weather', optionRequete).subscribe({
        next: data => {
          console.log(data);
          this.temperature = data.temperature;
          this.sky = data.sky;
          this.city = data.city;
        },
        error: error => {
          this.temperature = 0;
          this.sky = '';
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
