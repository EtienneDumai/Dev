import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title: string = 'Mon Application Angular';

  constructor() {
    this.afficherTitre();
  }

  afficherTitre(): void {
    console.log(this.title);
  }
}
