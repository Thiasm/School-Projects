import { DialogMoneyComponent } from './../../../Dialog/dialog-money/dialog-money.component';
import { MatDialog } from '@angular/material/dialog';
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';

@Component({
  selector: 'app-trade-money',
  templateUrl: './trade-money.component.html',
  styleUrls: ['./trade-money.component.scss']
})
export class TradeMoneyComponent implements OnInit {

  @Input() id: number;
  @Output() removeComponent = new EventEmitter<number>();

  input: string;
  value: number;
  arrow: string;
  currency: string;
  currencySec: string;

  constructor(public dialog: MatDialog, private http: HttpClient) {
  }

  ngOnInit(): void {
    this.input = '';
    this.currency = '';
    this.currencySec = '';
    this.openDialog();
    this.callApi();
  }

  removeWidget(): void {
    this.removeComponent.emit(this.id);
  }

  reloadWidget(): void {
    console.log('reload');
    this.callApi();
  }

    callApi(): void {
      const optionRequete = {
        headers: new HttpHeaders({
          'Access-Control-Allow-Origin': '*',
          currency1: this.currency,
          currency2: this.currencySec
        })
      };
      this.http.get<any>('http://localhost:8080/change', optionRequete).subscribe({
        next: data => {
          this.value = data.rate;
          if (this.value > 1) {
            this.arrow = 'up';
          }
          else if (this.value < 1) {
            this.arrow = 'down';
          }
        },
        error: error => {
          console.log('error');
          this.value = 0;
          this.currency = 'currency not found';
        }
      });
    }

  openDialog(): void {
    const dialogRef = this.dialog.open(DialogMoneyComponent, {
      data: {city: this.input}
    });
    dialogRef.afterClosed().subscribe(result => {
      if (!result) {
        this.currency = 'NONE';
        this.currencySec = 'NONE';
        this.value = 0;
        this.arrow = 'none';
        return;
      }
      this.currency = result.change;
      this.currencySec = result.changeSec;
      this.callApi();
    });
  }
}
