import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DialogMoneyComponent } from './dialog-money.component';

describe('DialogMoneyComponent', () => {
  let component: DialogMoneyComponent;
  let fixture: ComponentFixture<DialogMoneyComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DialogMoneyComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DialogMoneyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
