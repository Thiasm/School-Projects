import { MatDialog } from '@angular/material/dialog';
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { DialogTradeComponent } from './../../../Dialog/dialog-trade/dialog-trade.component';

@Component({
  selector: 'app-trade',
  templateUrl: './trade.component.html',
  styleUrls: ['./trade.component.scss']
})

export class TradeComponent implements OnInit {

  @Input() id: number;
  @Output() removeComponent = new EventEmitter<number>();

  input: string;
  price: number;
  change: number;
  arrow: string;
  symbol: string;

  constructor(public dialog: MatDialog, private http: HttpClient) {
  }

  ngOnInit(): void {
    this.input = '';
    this.symbol = 'Select a symbol';
    this.openDialog();
    this.callApi();
  }

  removeWidget(): void {
    this.removeComponent.emit(this.id);
  }

  reloadWidget(): void {
    this.callApi();
  }

    callApi(): void {
      const optionRequete = {
        headers: new HttpHeaders({
          'Access-Control-Allow-Origin': '*',
          company: this.symbol
        })
      };
      this.http.get<any>('http://localhost:8080/finance', optionRequete).subscribe({
        next: data => {
          console.log(data);
          this.price = data.price;
          this.change = data.change;
          if (this.change > 0) {
            this.arrow = 'up';
          }
          else {
            this.arrow = 'down';
          }
        },
        error: error => {
          console.log(error);
          this.price = 0;
          this.change = 0;
          this.symbol = 'Symbol not found';
        }
      });
    }

  openDialog(): void {
    const dialogRef = this.dialog.open(DialogTradeComponent, {
      data: {city: this.input}
    });
    dialogRef.afterClosed().subscribe(result => {
      this.symbol = result;
      if (result === '') {
        this.symbol = 'Symbol not found';
      }
      this.input = '';
      console.log(result);
      this.callApi();
    });
  }
}
