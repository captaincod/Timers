void setup() {
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  // (16*10^6) / (4*1024) - 1
  OCR1A = 3905; 
  // clear timer on compare
  TCCR1B = TCCR1B | (1 << WGM12);
  // 1024 prescaler
  TCCR1B = TCCR1B | (1 << CS12) | (1 << CS10);
  // timer compare interrupt
  TIMSK1 = TIMSK1 | (1 << OCIE1A);
  pinMode(LED_BUILTIN, OUTPUT);
  sei();
}
  
ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void loop() {
}
