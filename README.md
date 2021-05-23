# Train++ for Microcontrollers 

Train++ is an incremental training algorithm that trains ML models locally at the device level (e.g., on MCUs and small CPUs) using the full *n-samples* of high-dimensional data. Train++ transforms even the most resource-constrained edge devices into intelligent devices that can locally build their own knowledge base *on-the-fly* using the live data, thus creating smart self-learning and autonomous problem-solving AI devices.

## MCU boards, datasets chosen for Train++ performance evaluation

### Datasets (D1 - D7)

We converted all the listed datasets into MCU executable *.h* files and placed them inside the algorithm folder (Train_plus_plus). The datasets 1 to 7 are used for training binary classifiers on MCUs using Train++. The users have to uncomment their dataset of choice (header file at the beginning of the main algorithm program) to use it when training on MCUs.

1. [Iris Flowers](https://archive.ics.uci.edu/ml/datasets/iris "Google's Homepage"): Using Train++, we train a binary classifier to distinguish Iris Setosa from other flowers based on the input features.
2. [Heart Disease](https://archive.ics.uci.edu/ml/datasets/heart+Disease): After training, based on the input features, the Train++ trained classifier should be able to identify the presence of heart disease in the patient.
3. [Breast Cancer](https://www.kaggle.com/uciml/breast-cancer-wisconsin-data): Here we train a binary classifier that can find the class names (malignant or benign) based on the input features.
4. [MNIST Handwritten Digits](http://yann.lecun.com/exdb/mnist/): Here, we extracted data fields for digit 6, with positive and negative samples. Then using Train++, we trained a binary classifier on MCUs, that distinguishes digit 6 from other digits, based on the input features.
5. [Banknote Authentication](https://archive.ics.uci.edu/ml/datasets/banknote+authentication): Classifiers trained by Train++ using this dataset should be able to identify forged banknote-like specimens from the test set.
6. [Haberman's Survival](https://archive.ics.uci.edu/ml/datasets/Haberman's+Survival): The trained classifiers, based on the features from the test set, should be able to predict the survival status of patients who have undergone surgery. i.e., should classify whether the patient survived five years or longer, or the patient died within five years.
7. [Titanic](https://www.kaggle.com/c/titanic/data): The classifiers trained on MCUs using this dataset, for each passenger in the test set, should predict whether or not they survived the sinking of the Titanic.

### MCU boards (MCU1 - MCU5)

Using Arduino IDE we uploaded our Train++ algorithm and the datasets on the following popular open-source boards 

1. [nRF52840 Adafruit Feather](https://www.adafruit.com/product/4062): ARM Cortex-M4 @64MHz, 1MB Flash, 256KB SRAM
2. [STM32f103c8 Blue Pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html): ARM Cortex-M0 @72MHz, 128KB Flash, 20KB SRAM
3. [Adafruit HUZZAH32] (https://www.adafruit.com/product/3405): Xtensa LX6 @240MHz, 4MB Flash, 520KB SRAM
4. [Generic ESP32](https://www.espressif.com/en/products/devkits): Xtensa LX6 @240MHz, 4MB Flash, 520KB SRAM
5. [ATSAMD21G18 Adafruit METRO](https://www.adafruit.com/product/3505): ARM Cortex-M0+ @48 MHz, 256kB Flash, 32KB SRAM 

## Train++ Algorithm Performance Evaluation

Here we perform multiple datasets and MCUs based extensive experimental evaluation that aims to answer:

1. Is Train++ compatible with different MCU boards, and can it train ML models on MCUs using datasets with various feature dimensions and sizes?
2. Can Train++ load, train, and infer using high features and size datasets on limited memory MCU boards that have low hardware specification and no floating point unit (FPU), accelerated processing unit (APU), convolution operation accelerator (KPU) support?
3. What is the impact on accuracy when training ML models on MCUs using Train++, and how much does the accuracy vary in comparison with models trained on high resource setups?



**Tip:** When first time using the the Train++ code for training on MCUs, we recommend to use better resource boards like ESP32 and Adafruit Feather nrf52, then move on to using the tiny ones like Arduino Nano, Uno, etc.

