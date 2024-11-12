import { LoginComponent } from './Login/login.component';
import { DialogWeatherComponent } from './Dialog/dialog-weather/dialog-weather.component';
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppRoutingModule } from './app-routing.module';
import { HttpClientModule } from '@angular/common/http';

import { AppComponent } from './app.component';
import { MenuComponent } from './Home/menu/menu.component';
import { HeaderComponent } from './Home/header/header.component';
import { WidgetComponent } from './Home/Widget/widget/widget.component';
import { WeatherComponent } from './Home/Widget/weather/weather.component';
import { TradeComponent } from './Home/Widget/trade/trade.component';

import { DragDropModule } from '@angular/cdk/drag-drop';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { MatDialogModule } from '@angular/material/dialog';
import { MatButtonModule } from '@angular/material/button';
import { MatTableModule } from '@angular/material/table';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatInputModule } from '@angular/material/input';
import { MatToolbarModule } from '@angular/material/toolbar';
import { MAT_FORM_FIELD_DEFAULT_OPTIONS } from '@angular/material/form-field';
import { FormsModule } from '@angular/forms';
import { DialogTradeComponent } from './Dialog/dialog-trade/dialog-trade.component';
import { SpotifyComponent } from './Home/Widget/spotify/spotify.component';
import { DialogSpotifyComponent } from './Dialog/dialog-spotify/dialog-spotify.component';
import { MatSelectModule } from '@angular/material/select';
import { MatOptionModule } from '@angular/material/core';
import { WeatherWeekComponent } from './Home/Widget/weather-week/weather-week.component';
import { TradeMoneyComponent } from './Home/Widget/trade-money/trade-money.component';
import { SpotifyArtistComponent } from './Home/Widget/spotify-artist/spotify-artist.component';
import { DialogMoneyComponent } from './Dialog/dialog-money/dialog-money.component';
import { DialogSpotifyArtistComponent } from './Dialog/dialog-spotify-artist/dialog-spotify-artist.component';


@NgModule({
  declarations: [
    AppComponent,
    MenuComponent,
    HeaderComponent,
    WidgetComponent,
    WeatherComponent,
    TradeComponent,
    DialogWeatherComponent,
    DialogTradeComponent,
    SpotifyComponent,
    DialogSpotifyComponent,
    LoginComponent,
    WeatherWeekComponent,
    TradeMoneyComponent,
    SpotifyArtistComponent,
    DialogMoneyComponent,
    DialogSpotifyArtistComponent

  ],
  imports: [
    BrowserModule,
    BrowserAnimationsModule,
    AppRoutingModule,
    DragDropModule,
    HttpClientModule,
    FormsModule,

    MatButtonModule,
    MatFormFieldModule,
    MatDialogModule,
    MatInputModule,
    MatTableModule,
    MatToolbarModule,
    MatSelectModule,
    MatOptionModule,
  ],
  providers: [
    { provide: MAT_FORM_FIELD_DEFAULT_OPTIONS, useValue: { appearance: 'fill' } },
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
