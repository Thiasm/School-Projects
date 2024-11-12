import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { Component, OnInit, Inject } from '@angular/core';

export interface DialogData {
  symbol: string;
}

@Component({
  selector: 'app-dialog-trade',
  templateUrl: './dialog-trade.component.html'
})
export class DialogTradeComponent implements OnInit {

  constructor(
    public dialogRef: MatDialogRef<DialogTradeComponent>,
    @Inject(MAT_DIALOG_DATA) public data: DialogData) {}

  ngOnInit(): void {
  }

  onNoClick(): void {
    this.dialogRef.close();
  }
}
