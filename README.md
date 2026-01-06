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
