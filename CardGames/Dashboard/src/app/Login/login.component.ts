import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  clienId = '5e09808b877a4db9a0ed382ff59997a3';
  clientSecretId = '5b68bb3cb89c41ee8cee0291de630c49';
  url = 'https://accounts.spotify.com/authorize';

  constructor() { }

  ngOnInit(): void {
  }

  public login(): void {
    window.location.href = 'https://accounts.spotify.com/authorize?response_type=token&client_id=b985b7b00edc4c9ba3bdac14f40b548a&scope=user-read-private%20user-read-email&redirect_uri=http%3A%2F%2Flocalhost%3A4200%2Fdashboard%2F';
  }
}
