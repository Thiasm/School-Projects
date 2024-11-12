import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DialogTradeComponent } from './dialog-trade.component';

describe('DialogTradeComponent', () => {
  let component: DialogTradeComponent;
  let fixture: ComponentFixture<DialogTradeComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DialogTradeComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DialogTradeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
