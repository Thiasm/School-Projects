import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { Component, OnInit, Inject } from '@angular/core';

export interface DialogData {
  city: string;
}

@Component({
  selector: 'app-dialog-weather',
  templateUrl: './dialog-weather.component.html'
})
export class DialogWeatherComponent implements OnInit {

  constructor(
    public dialogRef: MatDialogRef<DialogWeatherComponent>,
    @Inject(MAT_DIALOG_DATA) public data: DialogData) {}

  ngOnInit(): void {
  }

  onNoClick(): void {
    this.dialogRef.close();
  }
}
