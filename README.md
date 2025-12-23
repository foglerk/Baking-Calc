BakedBakersCalc — C Baking Calculators

BakedBakersCalc is a small C command-line program that combines multiple bread-baking calculators into one menu-driven tool.
It is a learning project focused on core C fundamentals using real-world math.

This project practices:

Variables and data types

Arithmetic and casting

Formatted output (printf)

Basic input handling (scanf)

Simple branching (if, switch)

No loops, dynamic memory, or advanced libraries are used.

Features

BreadLab includes four calculators:

Hydration Percentage
Calculates dough hydration using:
(water / flour) × 100

Baker’s Percentages + Total Dough Weight
Calculates water %, salt %, and total dough weight.

Recipe Scaling
Scales water and salt while keeping baker’s ratios constant for a new flour amount.

Starter (Preferment) + Overall Hydration
Calculates starter hydration, total flour/water, overall hydration, and total dough weight.

All calculations correctly handle integer vs floating-point division using explicit casting.

Build and Run
Requirements

GCC or compatible C compiler

Linux, WSL, or macOS

Compile
gcc breadlab.c -o breadlab
Run
./breadlab
