#include <InternetButton.h>
#include <InternetButtonEvents.h>

InternetButton b = InternetButton();
InternetButtonEvents buttonEvents = InternetButtonEvents(b);

void setup() {
    Serial.begin(9600);
    
    buttonEvents.onButtonOn(buttonOnHandler);
    buttonEvents.onButtonClicked(buttonClickedHandler);
    buttonEvents.onAllButtonsClicked(allButtonsClickedHandler);

    b.begin(); 
}

void loop(){
    buttonEvents.update();
    
    // Use debounced button state values
    if (buttonEvents.allButtonsOn()) {
        b.allLedsOn(0,20,20);
    } else {
        b.allLedsOff();
    }
}

void buttonOnHandler(int buttonNumber) {
    Serial.print("Button pressed: ");
    Serial.println(buttonNumber);
}

void buttonClickedHandler(int buttonNumber) {
    Serial.print("Button clicked: ");
    Serial.println(buttonNumber);
    
    Particle.publish("buttonClicked", buttonNumber);
}

void allButtonsClickedHandler() {
    Serial.println("All buttons clicked");

    b.allLedsOn(20,20,0);
    delay(500);
    
    Particle.publish("allButtonsClicked");
}