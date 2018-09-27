unsigned int inputSize = 10;
unsigned int outputSize = 5;
unsigned int hiddenLayers = 1;
NeuralNetwork nn;
NeuralNetwork_ctor(&nn, inputSize, outputSize, hiddenLayers);


/* Configuring layer: "dense_3" */

// Initialise neurons for layer: "dense_3"
Neuron dense_3Neurons[4];

// Configure neuron[0] for layer "dense_3"
unsigned int dense_3Neuron0NumWeights = 11;
float dense_3Neuron0Weights[11] = {
   0.0 // This is the bias
  , -0.40068191289901733,  0.36619019508361816,   0.4440770149230957
  ,   -0.201199471950531,  -0.5043359994888306,  0.07052731513977051
  ,  -0.2763195335865021, -0.07570159435272217,  -0.5361230969429016
  ,  -0.3887658715248108
};
Neuron_ctor(&(dense_3Neurons[0]), dense_3Neuron0Weights, dense_3Neuron0NumWeights, Activation_ReLU);

// Configure neuron[1] for layer "dense_3"
unsigned int dense_3Neuron1NumWeights = 11;
float dense_3Neuron1Weights[11] = {
   0.0 // This is the bias
  ,  -0.5293107628822327, -0.05561172962188721,  0.10611832141876221
  ,  0.08319133520126343, -0.01060575246810913, -0.19308558106422424
  ,  -0.5178693532943726,  -0.4183781147003174,  0.43100619316101074
  ,  0.08593928813934326
};
Neuron_ctor(&(dense_3Neurons[1]), dense_3Neuron1Weights, dense_3Neuron1NumWeights, Activation_ReLU);

// Configure neuron[2] for layer "dense_3"
unsigned int dense_3Neuron2NumWeights = 11;
float dense_3Neuron2Weights[11] = {
   0.0 // This is the bias
  ,   0.6427160501480103,   0.3430444002151489,  0.06986850500106812
  , -0.46542906761169434,  0.17264479398727417,  0.28197622299194336
  ,  0.37659287452697754,  0.37368786334991455,  0.31695395708084106
  , 0.004977107048034668
};
Neuron_ctor(&(dense_3Neurons[2]), dense_3Neuron2Weights, dense_3Neuron2NumWeights, Activation_ReLU);

// Configure neuron[3] for layer "dense_3"
unsigned int dense_3Neuron3NumWeights = 11;
float dense_3Neuron3Weights[11] = {
   0.0 // This is the bias
  ,   0.1296747922897339,   0.4914509057998657,   0.5049178600311279
  ,  -0.4259410500526428,    0.547703742980957,  0.27244341373443604
  ,   0.6108393669128418,   0.5207527875900269, -0.016491413116455078
  ,  0.07393145561218262
};
Neuron_ctor(&(dense_3Neurons[3]), dense_3Neuron3Weights, dense_3Neuron3NumWeights, Activation_ReLU);


Layer dense_3Layer;
char * dense_3Name = "dense_3";
unsigned int dense_3NumNeurons = 4;
unsigned int dense_3InputSize = 10;
float dense_3LayerOutput[4] = { 0 };
Layer_ctor(
  &dense_3Layer,
  dense_3Name,
  dense_3InputSize,
  dense_3Neurons,
  dense_3NumNeurons,
  dense_3LayerOutput,
  Activation_ReLU
)

NeuralNetwork_addHiddenLayer(&nn, dense_3Name, (float *)dense_3Weights, dense_3NumNeurons);


/* Configuring layer: "dense_4" */

// Initialise neurons for layer: "dense_4"
Neuron dense_4Neurons[5];

// Configure neuron[0] for layer "dense_4"
unsigned int dense_4Neuron0NumWeights = 5;
float dense_4Neuron0Weights[5] = {
   0.0 // This is the bias
  ,   0.7614461183547974,   0.3891562223434448, -0.010097205638885498
  ,   0.4180140495300293
};
Neuron_ctor(&(dense_4Neurons[0]), dense_4Neuron0Weights, dense_4Neuron0NumWeights, Activation_SoftMax);

// Configure neuron[1] for layer "dense_4"
unsigned int dense_4Neuron1NumWeights = 5;
float dense_4Neuron1Weights[5] = {
   0.0 // This is the bias
  ,   0.8060158491134644, -0.02362161874771118,  -0.7549318671226501
  ,  -0.5478897094726562
};
Neuron_ctor(&(dense_4Neurons[1]), dense_4Neuron1Weights, dense_4Neuron1NumWeights, Activation_SoftMax);

// Configure neuron[2] for layer "dense_4"
unsigned int dense_4Neuron2NumWeights = 5;
float dense_4Neuron2Weights[5] = {
   0.0 // This is the bias
  ,  0.41510796546936035,   0.6670969724655151, -0.13636529445648193
  , -0.039108216762542725
};
Neuron_ctor(&(dense_4Neurons[2]), dense_4Neuron2Weights, dense_4Neuron2NumWeights, Activation_SoftMax);

// Configure neuron[3] for layer "dense_4"
unsigned int dense_4Neuron3NumWeights = 5;
float dense_4Neuron3Weights[5] = {
   0.0 // This is the bias
  ,   -0.541804313659668,  0.44585859775543213,   0.2707550525665283
  ,   0.7382404804229736
};
Neuron_ctor(&(dense_4Neurons[3]), dense_4Neuron3Weights, dense_4Neuron3NumWeights, Activation_SoftMax);

// Configure neuron[4] for layer "dense_4"
unsigned int dense_4Neuron4NumWeights = 5;
float dense_4Neuron4Weights[5] = {
   0.0 // This is the bias
  ,   -0.572191059589386,   0.6424148082733154, -0.26180893182754517
  ,   0.8045623302459717
};
Neuron_ctor(&(dense_4Neurons[4]), dense_4Neuron4Weights, dense_4Neuron4NumWeights, Activation_SoftMax);


Layer dense_4Layer;
char * dense_4Name = "dense_4";
unsigned int dense_4NumNeurons = 5;
unsigned int dense_4InputSize = 4;
float dense_4LayerOutput[5] = { 0 };
Layer_ctor(
  &dense_4Layer,
  dense_4Name,
  dense_4InputSize,
  dense_4Neurons,
  dense_4NumNeurons,
  dense_4LayerOutput,
  Activation_SoftMax
)

NeuralNetwork_addOutputLayer(&nn, (float *)dense_4Weights);
