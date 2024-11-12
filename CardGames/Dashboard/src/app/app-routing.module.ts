import { LoginComponent } from './Login/login.component';
import { WidgetComponent } from './Home/Widget/widget/widget.component';
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { MenuComponent } from './Home/menu/menu.component';
import { HeaderComponent } from './Home/header/header.component';
import { WeatherComponent } from './Home/Widget/weather/weather.component';

const routes: Routes = [
  { path: '', component: LoginComponent },
  { path: 'dashboard', component: HeaderComponent, children: [
    { path: '', component: MenuComponent, children: [
      { path: '', component: WidgetComponent, children: [
        { path: '', component: WeatherComponent }
      ] }
    ] }
  ] },

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
