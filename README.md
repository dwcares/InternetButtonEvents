# InternetButtonEvents
Provides clean, debounced, button state and click events for the [Particle Internet Button](https://docs.particle.io/guide/tools-and-features/button/photon).

This library simplifies scenarios around publishing events when buttons have been clicked by offering a set of callback-based button events for the Internet Button. It also debounces button pushes to provide more stable button states, with a configurable `clickThreshold`.

![Particle Internet Button](https://docs.particle.io/assets/images/internet-button-in-box.jpg)

## Getting Started
Connect your hardware to your Particle Internet Button, add the InternetButton and InternetButtonEvents library to your project and follow this simple example:

```
#include <InternetButton.h>
#include "InternetButtonEvents.h"

InternetButton b = InternetButton();
InternetButtonEvents buttonEvents = InternetButtonEvents(b);

void setup() { 
  buttonEvents.onButtonClicked(buttonClickedHandler);

  b.begin(); 
}

void loop() {
  buttonEvents.update();
}

void buttonClickedHandler(int buttonNumber) {
    Serial.print("Button clicked: ");
    Serial.println(buttonNumber);
}
```

See the [examples](examples) folder for more details.


## Button events
* `onButtonOn(callback)` - Called when any button is pressed.
* `onButtonOff(callback)` - Called when any button is was pressed and released.
* `onButtonClicked(callback)` - Called when any button is was clicked (equvalent to `onButtonOff`).
* `onAllButtonsOn(callback)` - Called when all buttons are pressed together.
* `onAllButtonsOff(callback)` - Called when all buttons were pressed then one or more buttons was released.
* `onAllButtonsClicked(callback)` - Called when all buttons are clicked (equvalent to `onAllButtonsClicked`).

## Button debouncing
InternetButtonEvents debouces button presses to limit accidental clicks. By default, a button needs to be pressed and released for `200` milliseconds for a click to register. 

This click threshold can be modified in the constructor for `InternetButtonEvents`.

```
int clickThreshold = 300;
InternetButtonEvents buttonEvents = InternetButtonEvents(b, clickThreshold);
```

You can inspect the debouced button state by using these helpers:

* `buttonOn(int buttonNumber)` - Get the debounced state of a specified button.
* `allButtonsOn()` - Get the debounced state if all buttons are clicked.

## Contributing

Here's how you can make changes to this library and eventually contribute those changes back.

To get started, [clone the library from GitHub to your local machine](https://help.github.com/articles/cloning-a-repository/).

Change the name of the library in `library.properties` to something different. You can add your name at then end.

Modify the sources in <src> and <examples> with the new behavior.

To compile an example, use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

After your changes are done you can upload them with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. Do `particle library add InternetButtonEvents_myname` to add the library to a project on your machine or add the InternetButtonEvents_myname library to a project on the Web IDE or Desktop IDE.

At this point, you can create a [GitHub pull request](https://help.github.com/articles/about-pull-requests/) with your changes to the original library. 

If you wish to make your library public, use `particle library publish` or `Publish` command.

## LICENSE
Copyright 2018 [@dwcares](https://twitter.com/dwcares)

Licensed under the MIT license
