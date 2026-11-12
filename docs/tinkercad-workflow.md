# Tinkercad Circuits workflow notes

This note documents the **scope of work**, not a claim that a general autonomous mechatronics agent has been built.

## Earlier practical session (9 November 2026)

1. Local terminal and Node.js runtime were checked.
2. A third-party Tinkercad Circuits MCP connection and signed-in state were checked.
3. An Arduino Uno + HC-SR04 + SG90 virtual practical was documented in a Word laboratory report.
4. The report recorded 10 cm → 90° and 30 cm → 0° virtual observations.

The original document noted that local Arduino CLI compilation and physical hardware tests were **not available**. Those checks are not implied by the existence of this repository.

## Reproducible example in this repo

- Use the wiring table in the root README; pins and threshold were selected here for teaching.
- Upload/paste the example Arduino sketch to a new Tinkercad Circuits simulation.
- Change object distance across the 20 cm boundary and observe the serial monitor/servo position.
- Compare the simulation with the host logic test results. Capture screenshots and run logs before claiming fresh simulation results.

## Workflow concept under investigation

```text
Human instruction or reference image
  → interpret parts and requirements
  → draft wiring and sketch
  → explicit human review
  → run simulation with authorized tools
  → read actual results and errors
  → produce cited, editable lab report
```

Automating each stage would require input validation, tool permission boundaries, error recovery, hardware limitations and credible result capture. It is **not implemented end to end** here.

## Third-party attribution

- Integration reference: [netchuu/tinkercad-circuits-mcp](https://github.com/netchuu/tinkercad-circuits-mcp).
- Tinkercad Circuits is a product of Autodesk.
- Neither the upstream MCP source nor the Tinkercad platform is represented as an original haammkaki product.
