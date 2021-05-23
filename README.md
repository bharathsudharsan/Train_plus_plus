# Train++ for Arduino Microcontrollers 

Train++ is an incremental training algorithm that trains ML models locally at the device level (e.g., on MCUs and small CPUs) using the full *n-samples* of high-dimensional data. Train++ transforms even the most resource-constrained edge devices into intelligent devices that can locally build their own knowledge base *on-the-fly* using the live data, thus creating smart self-learning and autonomous problem-solving AI devices.

## MCU boards, datasets chosen for Train++ performance evaluation

### Datasets (D1 - D7)

We converted all the listed datasets into MCU executable *.h* files and placed them inside the algorithm folder (Train_plus_plus). The datasets 1 to 7 are used for training binary classifiers on MCUs using Train++. The users have to uncomment their dataset of choice (header file at the beginning of the main algorithm program) to use it when training on MCUs.

D1: [Iris Flowers](https://archive.ics.uci.edu/ml/datasets/iris "Google's Homepage"): (4 features, 3 classes, 150 samples) <br/>
D2: [Heart Disease](https://archive.ics.uci.edu/ml/datasets/heart+Disease): : (13 features, 2 classes, 303 samples) <br/>
D3: [Breast Cancer](https://www.kaggle.com/uciml/breast-cancer-wisconsin-data): (30 features, 2 classes, 569 samples) <br/>
D4: [MNIST Handwritten Digits](http://yann.lecun.com/exdb/mnist/): (64 features, 10 classes, 1797 samples) <br/>
D5: [Banknote Authentication](https://archive.ics.uci.edu/ml/datasets/banknote+authentication): (5 features, 2 classes, 1372 samples) <br/>
D6: [Haberman's Survival](https://archive.ics.uci.edu/ml/datasets/Haberman's+Survival): (3 features, 2 classes, 306 samples) <br/>
D7: [Titanic](https://www.kaggle.com/c/titanic/data): (11 features, 2 classes,  1300 samples) <br/>

### MCU boards (MCU1 - MCU5)

Using Arduino IDE we uploaded our Train++ algorithm and the datasets on the following popular open-source boards 

MCU1: [nRF52840 Adafruit Feather](https://www.adafruit.com/product/4062): ARM Cortex-M4 @64MHz, 1MB Flash, 256KB SRAM <br/>
MCU2: [STM32f103c8 Blue Pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html): ARM Cortex-M0 @72MHz, 128KB Flash, 20KB SRAM <br/>
MCU3: [Adafruit HUZZAH32](https://www.adafruit.com/product/3405): Xtensa LX6 @240MHz, 4MB Flash, 520KB SRAM <br/>
MCU4: [Generic ESP32](https://www.espressif.com/en/products/devkits): Xtensa LX6 @240MHz, 4MB Flash, 520KB SRAM <br/>
MCU5: [ATSAMD21G18 Adafruit METRO](https://www.adafruit.com/product/3505): ARM Cortex-M0+ @48 MHz, 256kB Flash, 32KB SRAM <br/>

## Train++ Algorithm Performance Evaluation

Here we perform multiple datasets and MCUs based extensive experimental evaluation that aims to answer:

1. Is Train++ compatible with different MCU boards, and can it train ML models on MCUs using datasets with various feature dimensions and sizes?
2. Can Train++ load, train, and infer using high features and size datasets on limited memory MCU boards that have low hardware specification and no floating point unit (FPU), accelerated processing unit (APU), convolution operation accelerator (KPU) support?
3. What is the impact on accuracy when training ML models on MCUs using Train++, and how much does the accuracy vary in comparison with models trained on high resource setups?

### Experiment Procedure

Using Train++, for datasets D1-D4, we train a binary classifier on MCUs 1-5. For the first dataset D1, all the classifiers trained on MCUs 1-5 (using Train++) should distinguish Iris Setosa from other flowers based on the input features. Similarly for D2, the MCU trained classifiers should be able to identify the presence of heart disease in the patient. Similarly, for D3, the classifiers should be able to predict the class names based on the input features from the test set. For D4, digit six should be recognized from other digits. 

We compare the evaluation results of Train++ trained models with [Edge2Train](https://github.com/bharathsudharsan/Edge2Train) trained models. During comparison, we use the same datasets, MCUs, and procedure as from Edge2Train. The difference is, we use Train++ instead of Edge2Train's classifier training algorithm. 

### Training and Inference Time on MCUs

To explain the relationship between training time, train set size, and feature dimension, using Train++, we trained binary classifiers on all MCUs 1-5 by providing training sets of varying sizes. We illustrate the results for MCUs 2 & 5 in below Figure

![alt text](https://github.com/bharathsudharsan/Train_plus_plus/blob/master/setsize_vs_train_time_and_accuracy.png)

In this figure, the gap in the y-axis is the difference in the training time between the selected datasets, and for a clearer view, we marked this gap in ms. For MCUs 2 & 5, we noticed that the training time grows almost linearly with the number of training samples for all the datasets. For the Iris dataset with 4-dimensional features, MCU2 only took 4 ms to train on 105 samples, whereas it took 83 ms to train on the Digits dataset with 64-dimensional features. MCU5 is the slowest since it only has a 48 MHz clock and does not have FPU support. Hence it took 12 ms to train on 105 samples of the Iris dataset (3x times slower than MCU2) and 304 ms to train on the Digits dataset (3.6x times slower than MCU2). Comparing with Edge2Train results, it is apparent that using Train++, 

1. MCU1 trained 33.5 sec faster for the Iris dataset, 45.7 sec faster for Digits. 
2. MCU2 trained 226.1 sec faster for Iris, and Edge2Train could not load the Digits dataset due to SRAM overflow. Since Train++ has an incremental training characteristic, even after the SRAM requirement exceeds by +29 KB, we were able to load the dataset incrementally, to perform the training and complete training in 83 ms. 
3. MCUs 3 & 4 trained ≈ 10 sec faster for Iris and ≈ 25 sec faster for Digits. 
4. The slowest MCU5 trained 785.5 sec faster for Iris, and although the SRAM requirement exceeds by +63.62 KB, using Train++, MCU5 was able to load the entire dataset incrementally and train in 304ms. 


### ML Model Accuracy on MCUs

The highest onboard classification accuracy is 97.33% for the Iris (D1), 82.08% for Heart Disease (D2), 85.0% for Breast Cancer (D3), and 98.0% for Digits dataset (D4). In the above Figure, we illustrate the training sample size vs accuracy (accuracy scale in the right side y-axis). When comparing the accuracy of Train++ trained models with Edge2Train trained models, for the same Iris dataset, the accuracy improved by 7.3% and by 5.15% for the Digits dataset. This improvement is because our training algorithm enabled incremental loading of the full dataset. Other algorithms like SVMs work in batch mode, requiring full training data to be available in the limited MCU memory, thus sets an upper bound on the train set size. Hence, as shown our models achieved overall improved accuracy compared to the Edge2Train models, which were trained with limited data (unable to load full dataset due to memory constraints).

### Energy Consumption on MCUs

We calculate the energy (in Joules) consumed by MCUs to train and infer using Train++. We multiply the Current (Amperes) rating of MCUs with its Potential/Voltage (Volts) and corresponding task time (seconds). In this formulae, the task time is the training and inference time consumed by Train++ when executing on MCUs 1-5. Then, for comparison purposes, we plot thus calculated energy along with Edge2Train energy consumption results, in the form of a stacked bar chart

![alt text](https://github.com/bharathsudharsan/Train_plus_plus/blob/master/energy_comparison_for_train_and_infer.png)

From the above Figure (y-axis in base-10 log scale), it is apparent that Train++
1. Consumed ≈ 34000 - 65000x times less energy to train 
2. Consumed ≈ 34 - 66x times less energy for unit inference

For a given task that needs to be completed by using the same datasets on the same MCUs, Train++ achieved such significant energy consumption due to its high-performance characteristics (i.e., it trained and inferred at much higher speeds than other methods). Hence, when Train++ is used, MCUs can perform onboard model training and inference at the lowest power costs, thus enabling offline learning and model inference without affecting the IoT edge application routine and operating time of battery-powered devices

**Tip:** When first time using the the Train++ code for training ML models on MCUs, we recommend to use better resource boards like ESP32 and Adafruit Feather nrf52, then move on to using the tiny ones like Arduino Nano, Uno, etc.

