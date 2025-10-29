#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <SFML/Audio.hpp>

// constants
const unsigned int sampleRate = 44100; // cd quality
const unsigned int channels = 1; // mono
const double AMPLITUDE = 30000; // near max

// variables

void playTone(double frequency, float duration)
{
    // static casting is not mandatory but helpful
    unsigned int totalSamples = static_cast<unsigned int>(sampleRate * duration);
    std::vector<sf::Int16> samples(totalSamples);
    //sf::SoundBuffer* buffer = nullptr; // originally written in old school C++ memory
    std::unique_ptr<sf::SoundBuffer> buffer;
    sf::Sound sound;

    // Create a unique buffer object on the heap.
    // Why? It doesn't strain the stack.
    //buffer = new sf::SoundBuffer();
    buffer = std::make_unique<sf::SoundBuffer>();
    if(buffer == nullptr) // if this happens there is no memory to allocate
    {
        throw std::runtime_error("SFML::SOUNDBUFFER::ALLOCATION_FAILURE");
    }

    for(unsigned int i = 0; i < totalSamples; ++i)
    {
        // calculate time 't' for sample
        double t = double(i) / sampleRate;

        // sine wave!
        sf::Int16 sampleValue = static_cast<sf::Int16>(AMPLITUDE * std::sin(2.0
            * M_PI * frequency * t));

        samples[i] = sampleValue;
    }

    // If the buffer can't actually load the samples
    // then just gracefully back out
    if(!buffer->loadFromSamples(&samples[0], samples.size(), channels, sampleRate))
    {
        //delete buffer; // Only uncomment this if using raw pointers.

        std::cerr << "SOUNDBUFFER::SAMPLE::LOAD_FAILURE\n";
        return;
    }

    sound.setBuffer(*buffer);
    sound.play();

    // This creates a buffer between actual sample plays.
    // More is better for buffering, but could delay playback.
    while(sound.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::milliseconds(200));
    }

    /*
    if(buffer != nullptr)
    {
        delete buffer;
        buffer = nullptr;
    }
    */
}

// Please note this program can likely play more tones than this,
// BUT the sound buffer needs to be flushed clean to operate properly.

int main()
{
    try
    {
        playTone(440.0, 0.1);
        playTone(880.0, 0.1);
        playTone(1760.0, 0.1);

        playTone(0.0, 0.05); // silent break
            
        playTone(440.0, 0.1);
        playTone(880.0, 0.1);
        playTone(1760.0, 0.1);

        playTone(0.0, 0.05);

        playTone(440.0, 0.1);
        playTone(880.0, 0.1);
        playTone(1760.0, 0.1);

        playTone(0.0, 0.05);

        playTone(440.0, 0.1);
        playTone(880.0, 0.1);
        playTone(1760.0, 0.1);

        playTone(0.0, 0.05);

        playTone(330.0, 0.1);
        playTone(660.0, 0.1);
        playTone(1042.0, 0.1);

        playTone(0.0, 0.05);

        playTone(330.0, 0.1);
        playTone(660.0, 0.1);
        playTone(1042.0, 0.1);

        playTone(0.0, 0.05);

        playTone(330.0, 0.1);
        playTone(660.0, 0.1);
        playTone(1042.0, 0.1);

        playTone(0.0, 0.05);

        playTone(330.0, 0.1);
        playTone(660.0, 0.1);
        playTone(1042.0, 0.1);

        playTone(0.0, 0.05);

        playTone(375.0, 0.1);
        playTone(500.0, 0.1);
        playTone(795.0, 0.1);

        playTone(0.0, 0.05);

        playTone(375.0, 0.1);
        playTone(500.0, 0.1);
        playTone(795.0, 0.1);

        playTone(0.0, 0.05);

        playTone(375.0, 0.1);
        playTone(500.0, 0.1);
        playTone(795.0, 0.1);

        playTone(0.0, 0.05);

        playTone(375.0, 0.1);
        playTone(500.0, 0.1);
        playTone(795.0, 0.1);

        playTone(0.0, 0.05);

        playTone(250.0, 0.1);
        playTone(320.0, 0.1);
        playTone(490.0, 0.1);

        playTone(0.0, 0.05);

        playTone(250.0, 0.1);
        playTone(320.0, 0.1);
        playTone(520.0, 0.1);

        playTone(0.0, 0.05);

        playTone(250.0, 0.1);
        playTone(320.0, 0.1);
        playTone(580.0, 0.1);

        playTone(0.0, 0.05);

        playTone(250.0, 0.1);
        playTone(320.0, 0.1);
        playTone(660.0, 0.1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1; // failure
    }

    return 0;
}