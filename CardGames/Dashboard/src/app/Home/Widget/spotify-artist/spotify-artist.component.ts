import { DialogSpotifyArtistComponent } from './../../../Dialog/dialog-spotify-artist/dialog-spotify-artist.component';
import { MatDialog } from '@angular/material/dialog';
import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-spotify-artist',
  templateUrl: './spotify-artist.component.html',
  styleUrls: ['./spotify-artist.component.scss']
})

export class SpotifyArtistComponent implements OnInit {

  @Input() id: number;
  @Output() removeComponent = new EventEmitter<number>();

  input: string;
  first: string;
  second: string;
  third: string;
  fourth: string;
  fifth: string;
  selection: string;
  token: string;

  constructor(public dialog: MatDialog, private http: HttpClient, private route: ActivatedRoute) {
  }

  ngOnInit(): void {
    this.input = '';
    this.first = '';
    this.second = '';
    this.third = '';
    this.fourth = '';
    this.fifth = '';
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
    const obj = this.route.snapshot.fragment;
    let token;
    console.log(obj);
    token = obj.substr(obj.search('=') + 1, obj.search('&') - obj.search('=') - 1);
    console.log(token);
    const optionRequete = {
      headers: new HttpHeaders({
        'Access-Control-Allow-Origin': '*',
        genre: this.selection,
        token
      })
    };
    this.http.get<any>('http://localhost:8080/artists', optionRequete).subscribe({
      next: data => {
        console.log(data);
        if (data.error === false) {
          this.first = data.artists[0];
          this.second = data.artists[1];
          this.third = data.artists[2];
          this.fourth = data.artists[3];
          this.fifth = data.artists[4];
        }
        else {
          this.first = '';
          this.second = '';
          this.third = '';
          this.fourth = '';
          this.fifth = '';
          this.selection = 'Playlist not found';
        }
      },
      error: error => {
        this.first = '';
        this.second = '';
        this.third = '';
        this.fourth = '';
        this.fifth = '';
        this.selection = 'Playlist not found';
      }
    });
  }

  openDialog(): void {
    const dialogRef = this.dialog.open(DialogSpotifyArtistComponent, {
      data: {selection: this.input}
    });
    dialogRef.afterClosed().subscribe(result => {
      this.selection = result;
      this.input = '';
      this.callApi();
    });
  }
}
