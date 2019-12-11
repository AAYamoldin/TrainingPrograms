class ExtendedClock extends Clock {
  constructor(options){
    super(options);
    let { precision = 1000 } = options;
    this.precision = precision;
  }
  start(){
    this.render()
    setTimeout(() => this.render(), this.precision)
  }
}
