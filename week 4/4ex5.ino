unsigned int count;
bool previous;
unsigned char *reader = (unsigned char*) 0x23;

void setup() //To run on Arduino, just change this function to void setup(). Serial.begin(9600); 
{
Serial.begin(9600);

//For now, we are still using the Serial library
  for (;;)
  {
    bool current = (((*reader) & 0b01000000)!= 0);
    if (current && !previous) //If the pin is currently HIGH and previously LOW
    {
      count++;
      Serial.println(count);
   }
previous = current;
  }
}

void loop ()
{}
