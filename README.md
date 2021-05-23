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
![alt text](https://github.com/bharathsudharsan/Train_plus_plus/blob/master/setsize_vs_train_time_and_accuracy.png)

### ML Model Accuracy on MCUs

### Energy Consumption on MCUs
![alt text](https://github.com/bharathsudharsan/Train_plus_plus/blob/master/energy_comparison_for_train_and_infer.png)


**Tip:** When first time using the the Train++ code for training ML models on MCUs, we recommend to use better resource boards like ESP32 and Adafruit Feather nrf52, then move on to using the tiny ones like Arduino Nano, Uno, etc.

