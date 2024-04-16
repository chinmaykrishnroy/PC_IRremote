# PC_Remote
Transform any household remote into a powerful PC controller with this ESP32-based project. By utilizing an IR receiver module, the ESP32 decodes signals from the remote and generates custom keyboard commands. Connecting to the PC via Bluetooth Low Energy (BLE), it emulates a keyboard device, saving USB ports. Fully customizable, it extends beyond PC control, offering versatility for various applications.

## Working
IR Signal Reception: Any household remote control is used to send infrared (IR) signals. These signals are received by the IR receiver module connected to the ESP32.

Signal Decoding: The ESP32 decodes the received IR signals using appropriate decoding algorithms. This process involves identifying the protocol and extracting the specific commands sent by the remote.

Custom Command Generation: Based on the decoded IR signals, the ESP32 generates custom keyboard commands. These commands are mapped to specific actions that you want to perform on the PC, such as keystrokes, mouse movements, or shortcuts.

BLE Connection: Instead of directly connecting to the PC, the ESP32 communicates with it via Bluetooth Low Energy (BLE). The ESP32 acts as a BLE peripheral device, allowing it to establish a wireless connection with the PC.

Emulation as Keyboard Device: Once connected to the PC via BLE, the ESP32 emulates a keyboard device. This means that the PC recognizes the ESP32 as a keyboard input device, similar to a physical keyboard.

Sending Keyboard Commands: The ESP32 sends the custom keyboard commands to the PC over the BLE connection. These commands are interpreted by the PC as if they were coming from a standard keyboard, allowing the desired actions to be executed.

Customization: The project is fully customizable, allowing users to define their own mappings between IR signals and keyboard commands. This flexibility enables the remote control to be used for controlling various applications beyond just the PC.

Versatility: Due to its BLE connectivity and customizability, the remote control can be adapted for a wide range of applications beyond controlling a PC. It can be used to interface with other electronic devices, smart home systems, or IoT projects.
