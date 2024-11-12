import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { Component, OnInit, Inject } from '@angular/core';

export interface DialogData {
  selection: string;
}

@Component({
  selector: 'app-dialog-spotify-artist',
  templateUrl: './dialog-spotify-artist.component.html'
})
export class DialogSpotifyArtistComponent implements OnInit {
  constructor(public dialogRef: MatDialogRef<DialogSpotifyArtistComponent>,
              @Inject(MAT_DIALOG_DATA) public data: DialogData) {}

  ngOnInit(): void {
  }

  changeSelect(choice: string): void {
    this.data.selection = choice;
  }

  onNoClick(): void {
    this.dialogRef.close();
  }
}
