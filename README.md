# Train++: An incremental training algorithm to enable binary classifier training on MCUs

**Overview:** We provide *Train++* algorithm for all Arduino IDE supported MCUs. Train++ is our incremental training algorithm that can be used to train binary classifiers on MCUs using large volume, high dimensional, real-time data, thus producing self-learning IoT edge devices capable of learning to perform analytics for any target IoT use cases. 

**Datasets for onboard training:** We converted all the listed datasets into MCU executable *.h* files and placed them inside the algorithm folder. The datasets 1, 2, 3 and 4 are used for training binary classifiers on MCUs using *Opt-SGD*. The datasets 5 and 6 are used for training multi-class classifiers on MCUs using *Opt-OVO*. The users have to uncomment their dataset of choice (header file at the beginning of the main algorithm program) to use it when training on MCUs.

1. [Iris Flowers](https://archive.ics.uci.edu/ml/datasets/iris "Google's Homepage"): Using *Train++*, we train a binary classifier to distinguish Iris Setosa from other flowers based on the input features.
2. [Heart Disease](https://archive.ics.uci.edu/ml/datasets/heart+Disease): After training, based on the input features, the *Train++* trained classifier should be able to identify the presence of heart disease in the patient.
3. [Breast Cancer](https://www.kaggle.com/uciml/breast-cancer-wisconsin-data): Here we train a binary classifier that can find the class names (malignant or benign) based on the input features.
4. [MNIST Handwritten Digits](http://yann.lecun.com/exdb/mnist/): Here, we extracted data fields for digit 6, with positive and negative samples. Then using *Train++*, we trained a binary classifier on MCUs, that distinguishes digit 6 from other digits, based on the input features. 

**Experiment:** We uploaded our *Train++* algorithm on 5 popular open-source boards such as [nRF52840 Adafruit Feather](https://www.adafruit.com/product/4062), [STM32f103c8 Blue Pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html), [Generic ESP32](https://www.espressif.com/en/products/devkits), [ATSAMD21G18 Adafruit METRO](https://www.adafruit.com/product/3505) and trained binary classifier using the above datasets. 

**Tip:** Before using the implementation of our algorithms for onboard training, for the first time, we recommend users to use better resource boards like ESP32 and Adafruit Feather nrf52, then move on to using the tiny ones like Arduino Nano, Uno, etc.
