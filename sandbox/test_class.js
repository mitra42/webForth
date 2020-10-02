
function A(p) {
  console.log('A this=',this, 'p=',p);
}
function B(p) {
  console.log('B this=', this, 'p=', p);
  A.call(this,p);
}
const tt = []
const ttatt = []
function code(name, f) {
  tt.push(f);
  ttatt.push({name});
}
code("C", function x(p) {
  console.log('C this=', this, 'p=', p); B.call(this,p)});

class Forth {

  constructor() {
    this.f1 = "F1";
  }
}

f = new Forth();
B.call(f,10);
tt[0]
  .call(f,10)
x(10);
