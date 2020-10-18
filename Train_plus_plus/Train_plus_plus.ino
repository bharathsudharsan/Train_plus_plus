// To eliminate the problems with min/max for ESP32
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
#define abs(x) ((x) > 0 ? (x) : -(x))
#include <string.h>

// Uncomment the dataset of choice to use it when training on MCUs.
//#include "Iris_flowers.h"
//#include "Heart_disease.h"
//#include "Digits_binary.h"
//#include "Breast_cancer.h"
//#include "haberman_survival_train_test.h"
#include "banknote_authentication_train_test.h"
//#include "titanic_train_test.h"

// Function to evaluate the multi-class classifiers.
        class eval_fn {
        public:
            eval_fn() :
                    t_p(0), t_n(0), f_p(0), f_n(0) {
            }
            void truevsfalse(int actual_val, int predicted_val) {
                if (predicted_val > 0 && predicted_val == actual_val)
                    t_p++;
                else if (predicted_val > 0 && predicted_val != actual_val)
                    f_p++;
                else if (predicted_val <= 0 && predicted_val == actual_val)
                    t_n++;
                else
                    f_n++;  }
            float accuracy() {
                return (1.0f * t_p + t_n) / total();   }
            unsigned int total() {
                return t_p + t_n + f_p + f_n;  }
        protected:
            unsigned int t_p; unsigned int t_n; unsigned int f_p; unsigned int f_n;
        };

        template<unsigned int size>
        float dot(float x[size], float w[size]) {
            float sum = 0;
            for (unsigned int i = 0; i < size; i++)
                sum += x[i] * w[i];
            return sum; }

        template<unsigned int num_features>
        class Base_classifier {
        public:
            virtual void classifier_fit(float x[num_features], int y) = 0;
            virtual int classifier_predict(float x[num_features]) = 0;
            virtual void set(const char *param, float value) {
            }

        protected:
            template<typename T>
            void param_set(const char *param_name, const char* target_name, T *param, T value) {
                if (strcmp(param_name, target_name) == 0)
                    *param = value;  } };

        template<unsigned int features_dim>
        class Train_plus_plus : public Base_classifier<features_dim> {
        public:

            Train_plus_plus() {
                model_params.C = 0.01;

                for (unsigned int i = 0; i < features_dim; i++)
                    model_weights[i] = 0;  }

            void setC(float C) {
                set("C", C); }

            void classifier_fit(float x[features_dim], int datafields_label) {
                datafields_label = datafields_label > 0 ? 1 : -1;

                float model_loss = max(0, 1 - (datafields_label * dot<features_dim>(x, model_weights)));
                float x_norm = dot<features_dim>(x, x);
                float tau_val = model_loss / (x_norm + (1 / (2 * model_params.C))) * datafields_label;

                for (unsigned int i = 0; i < features_dim; i++)
                    model_weights[i] += tau_val * x[i];  }

            int classifier_predict(float x[features_dim]) {
                return dot<features_dim>(x, model_weights) > 0 ? 1 : -1;  }

            void set(const char *param, float value) {
                this->param_set(param, "C", &model_params.C, value); }

        protected:
            struct {
                float C;
            } model_params;
            float model_weights[features_dim];     };

int temp, temp1 = 0;

void setup() {
    Serial.begin(115200);
    delay(5000);}

int read_user_ip(String str_read, int max_allowed_size) {
    Serial.print(str_read);
    Serial.print(" (");
    Serial.print(max_allowed_size);
    Serial.print(" max) ");
    while (!Serial.available()) delay(1);
    int n = Serial.readStringUntil('\n').toInt();
    Serial.println(n);
    return max(0, min(n, max_allowed_size));
}

void loop() {
    int data_samples;
    Train_plus_plus<FEATURES_DIMEN> call_fn;
    eval_fn score;

    data_samples = read_user_ip("Enter a train set size ", DATASET_ROWS - 2);

    if (data_samples == 0)
        return;

    call_fn.setC(1);
    
    Serial.print("Starting to train using the entered train set size");
    time_t start = millis();
    for (uint16_t i = 0; i < data_samples; i++)
        call_fn.classifier_fit(X[i], y[i]);
    Serial.println();   
    Serial.print("It took ");
    temp1 = millis() - start;
    Serial.print(temp1);
    Serial.print("ms to train ");
    Serial.println();

    // Predict using onboard trained classifier
    start = millis();
    for (uint16_t i = data_samples; i < DATASET_ROWS; i++) {
        int predicted_val = call_fn.classifier_predict(X[i]);
        int actual_val = y[i] > 0 ? 1 : -1;

        score.truevsfalse(actual_val, predicted_val);

        Serial.print(predicted_val == actual_val ? "[ OK]" : "[ERR]");
        Serial.print(" Predicted ");
        Serial.print(predicted_val > 0 ? "+" : "");
        Serial.print(predicted_val);
        Serial.print(" vs ");
        Serial.print(actual_val > 0 ? "+" : "");
        Serial.print(actual_val);
        Serial.println(" actual");    }
    Serial.print("It took ");
    temp = millis() - start;
    Serial.print(temp);
    Serial.print("ms for infering using the full test set");
    Serial.println();
    Serial.print("Accuracy: ");
    Serial.print(round(100 * score.accuracy()));
    Serial.print("% out of ");
    Serial.print(score.total());
    Serial.println(" predictions"); }
