import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DialogSpotifyArtistComponent } from './dialog-spotify-artist.component';

describe('DialogSpotifyArtistComponent', () => {
  let component: DialogSpotifyArtistComponent;
  let fixture: ComponentFixture<DialogSpotifyArtistComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DialogSpotifyArtistComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DialogSpotifyArtistComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
