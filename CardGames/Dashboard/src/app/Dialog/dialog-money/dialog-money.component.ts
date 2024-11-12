import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { Component, OnInit, Inject } from '@angular/core';

export interface DialogData {
  change: string;
  changeSec: string;
}

@Component({
  selector: 'app-dialog-money',
  templateUrl: './dialog-money.component.html'
})
export class DialogMoneyComponent implements OnInit {

  constructor(
    public dialogRef: MatDialogRef<DialogMoneyComponent>,
    @Inject(MAT_DIALOG_DATA) public data: DialogData) {}

  ngOnInit(): void {
  }

  onNoClick(): void {
    this.dialogRef.close();
  }
}
