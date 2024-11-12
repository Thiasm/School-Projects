import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DialogSpotifyComponent } from './dialog-spotify.component';

describe('DialogSpotifyComponent', () => {
  let component: DialogSpotifyComponent;
  let fixture: ComponentFixture<DialogSpotifyComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DialogSpotifyComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DialogSpotifyComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
