import os

def write_model(model, file_name='model.h'):
    f = open(os.path.join('gen', file_name) ,'w')
    
    hidden_layers = len(model.layers) - 2
    input_size = model.layers[0].input_shape[1]
    output_size = model.layers[-1].output_shape[1]
    output_layer = model.layers[-1]
    
    for layer in model.layers:
        layerName = layer.name
        weights = layer.get_weights()
        is_input_layer = len(weights) == 0
        is_output_layer = layer.name == output_layer.name
        
        if is_input_layer:
            f.write('unsigned int inputSize = {0};\n'.format(input_size))
            f.write('unsigned int outputSize = {0};\n'.format(output_size))
            f.write('unsigned int hiddenLayers = {0};\n'.format(hidden_layers))    
            f.write('NeuralNetwork nn;\n')
            f.write('NeuralNetwork_ctor(&nn, inputSize, outputSize, hiddenLayers);\n')
        else:
            W = weights[0].T
            b = weights[1]
            numUnits = W.shape[0]
            numWeights = W.shape[1]
            
            f.write('\n\n/* Configuring layer: "{0}" */\n\n'.format(layerName))
            
            f.write('char * {0}Name = "{0}";\n'.format(layerName));
            f.write('unsigned int {0}NumNeurons = {1};\n'.format(layerName, numUnits))
            f.write('unsigned int {0}InputSize = {1};\n'.format(layerName, numWeights))
            f.write('float {0}Weights[{1}][{2}] = {{\n'.format(layerName, numUnits, numWeights+1))
            
            for unit in range(numUnits):
                # Write the bias in the first entry
                f.write('  {{ {0}'.format(b[unit]))
                for j in range(numWeights):
                    f.write(', {0}'.format(W[unit][j]))
                
                f.write('},\n')
            
            f.write('};\n')
            
            if not is_output_layer:
                f.write('NeuralNetwork_addHiddenLayer(&nn, {0}Name, (float *){0}Weights, {0}NumNeurons);\n'.format(layerName))
            else:
                f.write('NeuralNetwork_addOutputLayer(&nn, (float *){0}Weights);\n'.format(layerName))
    f.close
