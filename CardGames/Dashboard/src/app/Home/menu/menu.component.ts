import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-menu',
  templateUrl: './menu.component.html',
  styleUrls: ['./menu.component.scss']
})
export class MenuComponent implements OnInit {

  List: Array<{id: number, type: string}> = [];
  count = 0;

  constructor() {}

  ngOnInit(): void {
  }

  initWidget(value: string)
  {
    this.List.push(
      { id: this.count , type: value }
    );
    this.count++;
  }
}
