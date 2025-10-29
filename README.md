# ToneGenerator
A primitive sine wave tone generator.

WARNING
----------------

Please only use this program with your volume relatively LOW.

The program plays tones through speakers or headphones close to peak volume.

BRANCHES
----------------

There is only one branch to this project on `main`.

There are no planned future updates to this project but you may fork it under it's license terms.

HOW IT WORKS
------------

The project requires an understanding of a couple of things.
The different aspects of vibrational data (sound) and how to make a computer emulate that data.

This particular program plays simple, non-sharp tones.

This program reads in integer data, transforms it into a sound wave (sine), then outputs the sound through your speakers or headphones.

It's nothing too mystical it's a pretty standard int-to-waveform conversion.

WHY I MADE THIS
---------------

To demonstrate simple tone generation using nothing but the built in SFML libraries.

COMPILATION
-----------

*** If you're on Linux: ***

You should only need the SFML and the standard Linux math libraries to run this program.

The bash scripts provided make it easy to run the binary straight from the folder in a terminal, or you can build and run from the build folder.

*** If you're on Windows: ***

FOR VISUAL STUDIO
-----------

You should be able to build this program in Visual Studio using it's CMake protocols.

Please note that if you are using older versions of CMake it can (technically) work,
because the CMakeLists provided don't use any fancy new CMake options.

Please keep in mind that if you are using an older version of CMake for whatever reason, this program may not build as intended.

The typical way to build a project like this is to follow Visual Studio's 'BUILD ALL' CMake command, which should generate a pretty binary that you can use.

Use your discretion.