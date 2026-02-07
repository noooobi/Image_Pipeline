# Image-processing dataflow system

## Overview
The video processing pipeline begins with the webcam, which captures raw video frames from the camera hardware. These frames are first passed to the frame grab stage, which retrieves, buffers, and standardizes them for further processing. Next, the frames flow through the processing pipeline, where a series of modular stages can apply transformations, filters, or analysis in sequence. Finally, the processed frames reach the display or sink stage, which outputs them to a screen, saves them to a file, or streams them over a network. This design is modular, extensible, and allows each stage to operate independently, supporting efficient data flow and potential multithreading for performance.

---

## Big-picture architecture
┌──────────┐   ┌────────────┐   ┌──────────────┐   ┌──────────┐
│  Webcam  │→→ │ Frame Grab │→→ │ Processing    │→→ │ Display  │
│ (driver) │   │   Stage    │   │  Pipeline     │   │ / Sink   │
└──────────┘   └────────────┘   └──────────────┘   └──────────┘

Core design idea: staged pipeline + queues

Each stage:

Consumes frames

Transforms them

Pushes them forward

### Data moves like this:
Camera Thread
    ↓
[ Lock-free / bounded queue ]
    ↓
Processing Thread(s)
    ↓
[ Queue ]
    ↓
Sink (display / file / network)

## Visual mental model (very important)
[Frame 42]
   |
   v
[Queue A]  (capture → processing)
   |
   v
[Stage 1] → [Stage 2] → [Stage 3]
   |
   v
[Queue B]  (processing → output)
   |
   v
[Display]


## Directory structure
image_pipeline/
├── core/
│   ├── Frame.h
│   ├── Queue.h
│   └── Pipeline.h
├── capture/
│   └── WebcamCapture.cpp
├── stages/
│   ├── Grayscale.cpp
│   ├── Blur.cpp
│   └── Edge.cpp
├── output/
│   └── Display.cpp
├── app/
│   └── main.cpp