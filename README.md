# Train++: A high-performance incremental binary classifier training algorithm for MCUs

we present Train++, an incremental training algorithm that trains ML models locally at the device level (e.g., on MCUs and small CPUs) using the full *n-samples* of high-dimensional data. Train++ transforms even the most resource-constrained edge devices into intelligent devices that can locally build their own knowledge base *on-the-fly* using the live data, thus creating smart self-learning and autonomous problem-solving AI devices.

## Datasets for onboard training

We converted all the listed datasets into MCU executable *.h* files and placed them inside the algorithm folder. The datasets 1 to 7 are used for training binary classifiers on MCUs using Train++. The users have to uncomment their dataset of choice (header file at the beginning of the main algorithm program) to use it when training on MCUs.

1. [Iris Flowers](https://archive.ics.uci.edu/ml/datasets/iris "Google's Homepage"): Using Train++, we train a binary classifier to distinguish Iris Setosa from other flowers based on the input features.
2. [Heart Disease](https://archive.ics.uci.edu/ml/datasets/heart+Disease): After training, based on the input features, the Train++ trained classifier should be able to identify the presence of heart disease in the patient.
3. [Breast Cancer](https://www.kaggle.com/uciml/breast-cancer-wisconsin-data): Here we train a binary classifier that can find the class names (malignant or benign) based on the input features.
4. [MNIST Handwritten Digits](http://yann.lecun.com/exdb/mnist/): Here, we extracted data fields for digit 6, with positive and negative samples. Then using Train++, we trained a binary classifier on MCUs, that distinguishes digit 6 from other digits, based on the input features.
5. [Banknote Authentication](https://archive.ics.uci.edu/ml/datasets/banknote+authentication): Classifiers trained by Train++ using this dataset should be able to identify forged banknote-like specimens from the test set.
6. [Haberman's Survival](https://archive.ics.uci.edu/ml/datasets/Haberman's+Survival): The trained classifiers, based on the features from the test set, should be able to predict the survival status of patients who have undergone surgery. i.e., should classify whether the patient survived five years or longer, or the patient died within five years.
7. [Titanic](https://www.kaggle.com/c/titanic/data): The classifiers trained on MCUs using this dataset, for each passenger in the test set, should predict whether or not they survived the sinking of the Titanic.

**Experiment:** Using Arduino IDE we uploaded our Train++ algorithm on the following popular open-source boards [nRF52840 Adafruit Feather](https://www.adafruit.com/product/4062), [STM32f103c8 Blue Pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html), [Generic ESP32](https://www.espressif.com/en/products/devkits), [ATSAMD21G18 Adafruit METRO](https://www.adafruit.com/product/3505) and trained binary classifier using the above datasets. We followed exactly the same setup as from the state-of-the-art [Edge2Train framework](https://dl.acm.org/doi/pdf/10.1145/3410992.3411014). Then when comparing both the results, we made the following observations. 

1. Our method reduces the onboard binary classifier training time by 10 - 226 sec across the same MCUs. 
2. Our models infer for the entire test set in lesser time than the Edge2Train trained model's unit inference time. 
3. The accuracy improved by 5.15 - 7.3%  since our incremental training method enabled loading the full *n-samples* of the high-dimensional datasets.



**Tip:** Before using the implementation of our algorithms for onboard training, for the first time, we recommend users to use better resource boards like ESP32 and Adafruit Feather nrf52, then move on to using the tiny ones like Arduino Nano, Uno, etc.

