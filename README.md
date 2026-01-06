## Project Overview

The goal of this assignment is to design and implement an embedded-friendly software library that serializes structured smart meter data into a predefined JSON format.

This project represents a realistic part of a future smart-meter or w-M-Bus data pipeline, where measurement data is stored in internal data structures and then serialized into JSON for transmission to a gateway or backend interface.

The scope of this assignment is intentionally limited. Topics such as w-M-Bus radio communication, OMS compliance, encryption, and real meter hardware interaction are explicitly out of scope.

The primary focus of this project is on:
- Clean and maintainable software architecture
- Clear and well-defined public API design
- Embedded-oriented implementation with controlled memory usage
- Robust error handling and buffer safety
- Clear and complete documentation suitable for firmware development

The library is designed to be transport-agnostic and independent of any specific communication interface.


## Platform and Development Environment

The Arduino framework was selected as the development environment for this assignment.

Although STM32CubeIDE is the preferred platform, the Arduino framework provides a lightweight and accessible environment that is well-suited for embedded firmware development and rapid prototyping.

Using Arduino allows the core logic of the serialization library to remain close to bare-metal C code while simplifying build and execution. This makes it easier to demonstrate the embedded-friendly design, memory control, and API clarity required by the assignment.

The implemented library is platform-agnostic and can be ported to STM32 or ESP32 environments with minimal changes.


## Programming Language

The C programming language was selected for implementing the serialization library.

C is widely used in embedded systems due to its low runtime overhead, deterministic behavior, and direct control over memory. These characteristics make it well-suited for resource-constrained environments such as microcontrollers.

The implementation avoids unnecessary dependencies and does not rely on any external JSON libraries. JSON serialization is performed manually to maintain full control over memory usage and output formatting.

The design emphasizes controlled memory usage, clear buffer size management, and robust error handling to prevent buffer overflows and invalid output.

The code is written in a clear and modular manner to ensure readability, maintainability, and ease of future extension.
