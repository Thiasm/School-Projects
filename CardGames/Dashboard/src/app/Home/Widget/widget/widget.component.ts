import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-widget',
  templateUrl: './widget.component.html',
  styleUrls: ['./widget.component.scss']
})


export class WidgetComponent implements OnInit {

  constructor() { }

  @Input() List: Array<{id: number, type: string}> = [];

  ngOnInit(): void {
  }

  removeWidget(event: number): void {
    const index = this.List.findIndex(x => x.id === event);
    this.List.splice(index, 1);
  }

}
