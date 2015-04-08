#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED
//Functions
extern unsigned int testRandomNum();
extern void entropy();
extern void defineSeed(int);
extern unsigned int randomNum();
extern unsigned int returnSeed();
extern unsigned int polyRollDice(int number, int die);
extern void randomTest();
extern unsigned long randomMT();
extern void initializeRandomMT();

/**
 * This funciton is never intended to be directly called, instead it is designed to work with the A2D library (v1.1.0+)
 * This function will be sent as the Averaging Style pointer
 * The A2D should be setup to use 16 bits of resolution and take 16 samples (max samples)
 * It is recommended that a finishing function be added to the A2D channel that can always grab and store the latest truly random variable
 * To get a truly random number, you require an analog source that has some jitter. A truly stable source will not provide a random number, you require entropy in the system
 * An analog pin connected to a 100nF capacitor to ground has proven to be a good source
 * @param channel The A2D will tell the function what channel is being sampled, this function ignores that information as it is irrelevant
 * @param A2D_Buffer This is a direct pointer to the A2D sample buffer (Specifically ADC1BUF0) which is used to look at the least significant bit of each sample to build a truely random number
 * @param samples This indicated how many samples were taken. It will work with fewer than 16 samples, but 16 samples will give you a full two byte integer random number
 * @returns The truly random number is returned where it will be averaged and stored. If you have setup the A2D channel correctly, it should not alter it in anyway
 */
int True_16_bit_RNG_Generator(int channel, volatile unsigned int *A2D_Buffer, int samples);

#endif // RANDOM_H_INCLUDED