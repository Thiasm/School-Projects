import { MatDialog } from '@angular/material/dialog';
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { DialogSpotifyComponent } from './../../../Dialog/dialog-spotify/dialog-spotify.component';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-spotify',
  templateUrl: './spotify.component.html',
  styleUrls: ['./spotify.component.scss']
})

export class SpotifyComponent implements OnInit {

  @Input() id: number;
  @Output() removeComponent = new EventEmitter<number>();

  input: string;
  first: string;
  second: string;
  third: string;
  selection: string;
  token: string;

  constructor(public dialog: MatDialog, private http: HttpClient, private route: ActivatedRoute) {
  }

  ngOnInit(): void {
    this.input = '';
    this.first = '';
    this.second = '';
    this.third = '';
    this.selection = 'Select a Playlist';
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
    var obj = this.route.snapshot.fragment
    var token;
    console.log(obj);
    token = obj.substr(obj.search('=') + 1, obj.search('&') - obj.search('=') - 1);
    console.log(token);
    const optionRequete = {
      headers: new HttpHeaders({
        'Access-Control-Allow-Origin': '*',
        playlist: this.selection,
        token: token
      })
    };
    this.http.get<any>('http://localhost:8080/playlist', optionRequete).subscribe({
      next: data => {
        console.log(data);
        if (data.error == false) {
          this.first = data.tracks[0];
          this.second = data.tracks[1];
          this.third = data.tracks[2];
        }
        else {
          this.first = '';
          this.second = '';
          this.third = '';
          this.selection = 'Playlist not found';
        }
      },
      error: error => {
        this.first = '';
        this.second = '';
        this.third = '';
        this.selection = 'Playlist not found';
      }
    });
  }

  openDialog(): void {
    const dialogRef = this.dialog.open(DialogSpotifyComponent, {
      data: {selection: this.input}
    });
    dialogRef.afterClosed().subscribe(result => {
      this.selection = result;
      if (result === '') {
        this.selection = 'Playlist not found';
      }
      this.input = '';
      console.log(result);
      this.callApi();
    });
  }
}
