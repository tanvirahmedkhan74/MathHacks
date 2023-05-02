#include <bits/stdc++.h>

int main()
{
    std::vector<double> height = {your_height, 71.52, 69.4, 68.22, 67.79, 68.7, 69.8, 70.01, 67.9, 66.78, 66.49, 67.62, 68.3, 67.12, 68.28, 71.09, 66.46, 68.65, 71.23, 67.13};
    std::vector<double> weight = {your_weight, 136.49, 153.03, 142.34, 144.3, 123.3, 141.49, 136.46, 112.37, 120.67, 127.45, 114.14, 125.61, 122.46, 116.09, 140, 129.5, 142.97, 137.9, 124.04};

    // Printing out the height and weight in x1 y1 x2 y2 format
    for (int i = 0; i < 20; i++)
    {
        std::cout << height[i] << " " << weight[i] << "\n";
    }

    // std::sort(height.begin(), height.end());
    // std::sort(weight.begin(), weight.end());

    std::cout << "Height\n";
    for (int i = 0; i < 20; i++)
    {
        std::cout << i + 1 << ". " << height[i] << "\n";
    }

    std::cout << "Weight\n";
    for (int i = 0; i < 20; i++)
    {
        std::cout << i + 1 << ". " << weight[i] << "\n";
    }

    // Sum of height and weight
    double sum_height = 0;
    double sum_weight = 0;
    for (int i = 0; i < 20; i++)
    {
        sum_height += height[i];
        sum_weight += weight[i];
    }
    std::cout << "Sum of height: " << sum_height << "\n";
    std::cout << "Sum of weight: " << sum_weight << "\n";


    // Finding out the mean for height and weight
    double sum = 0;
    for (int i = 0; i < 20; i++)
    {
        sum += height[i];
    }
    double hmean = sum / 20.0;
    std::cout << "Mean of height: " << hmean << "\n";

    sum = 0;
    for (int i = 0; i < 20; i++)
    {
        sum += weight[i];
    }
    double wmean = sum / 20.0;
    std::cout << "Mean of weight: " << wmean << "\n";

    // Finding out the median for height and weight
    double median = 0;
    if (20 % 2 == 0)
    {
        median = (height[9] + height[10]) / 2.0;
    }
    else
    {
        median = height[10];
    }
    std::cout << "Median of height: " << median << "\n";

    if (20 % 2 == 0)
    {
        median = (weight[9] + weight[10]) / 2.0;
    }
    else
    {
        median = weight[10];
    }
    std::cout << "Median of weight: " << median << "\n";

    // Finding the deviation about the mean and squared deviation about the mean for height and weight
    std::vector<double> dev_height;
    std::vector<double> dev_weight;
    std::vector<double> sq_dev_height;
    std::vector<double> sq_dev_weight;

    for (int i = 0; i < 20; i++)
    {
        dev_height.push_back(height[i] - hmean);
        dev_weight.push_back(weight[i] - wmean);
        sq_dev_height.push_back(pow(dev_height[i], 2));
        sq_dev_weight.push_back(pow(dev_weight[i], 2));
    }

    // Sum of deviations about the mean for height and weight
    double sum_dev_height = 0;
    double sum_dev_weight = 0;
    for (int i = 0; i < 20; i++)
    {
        sum_dev_height += dev_height[i];
        sum_dev_weight += dev_weight[i];
    }
    std::cout << "\nSum of deviations about the mean for height: " << sum_dev_height << "\n";
    std::cout << "Sum of deviations about the mean for weight: " << sum_dev_weight << "\n";

    // Sum of squared deviations about the mean for height and weight
    double sum_sq_dev_height = 0;
    double sum_sq_dev_weight = 0;
    for (int i = 0; i < 20; i++)
    {
        sum_sq_dev_height += sq_dev_height[i];
        sum_sq_dev_weight += sq_dev_weight[i];
    }
    std::cout << "\nSum of squared deviations about the mean for height: " << sum_sq_dev_height << "\n";
    std::cout << "Sum of squared deviations about the mean for weight: " << sum_sq_dev_weight << "\n";

    // Printing the height , dev about the height, sq dev about the height
    std::cout << "\nHeight\tDeviation\tSquared Deviation\n";
    for (int i = 0; i < 20; i++)
    {
        std::cout << height[i] << "\t" << dev_height[i] << "\t\t" << sq_dev_height[i] << "\n";
    }

    // Printing the weight , dev about the weight, sq dev about the weight
    std::cout << "\nWeight\tDeviation\tSquared Deviation\n";
    for (int i = 0; i < 20; i++)
    {
        std::cout << weight[i] << "\t" << dev_weight[i] << "\t\t" << sq_dev_weight[i] << "\n";
    }

    // Finding the variance for height and weight
    double variance_height = 0;
    double variance_weight = 0;
    for (int i = 0; i < 20; i++)
    {
        variance_height += sq_dev_height[i];
        variance_weight += sq_dev_weight[i];
    }
    variance_height /= 19;
    variance_weight /= 19;
    std::cout << "\nVariance of height: " << variance_height << "\n";
    std::cout << "Variance of weight: " << variance_weight << "\n";

    // Finding the standard deviation for height and weight
    double std_dev_height = sqrt(variance_height);
    double std_dev_weight = sqrt(variance_weight);
    std::cout << "\nStandard deviation of height: " << std_dev_height << "\n";
    std::cout << "Standard deviation of weight: " << std_dev_weight << "\n";

    // Finding the coefficient of variation for height and weight
    double coeff_var_height = std_dev_height / hmean;
    double coeff_var_weight = std_dev_weight / wmean;
    std::cout << "\nCoefficient of variation of height: " << coeff_var_height << "\n";
    std::cout << "Coefficient of variation of weight: " << coeff_var_weight << "\n";

    // Compute five number summary and interquantile range (IQR) of Height and Weight
    double min_height = height[0];
    double max_height = height[19];
    double min_weight = weight[0];
    double max_weight = weight[19];
    double q1_height = (height[4] + height[5]) / 2.0;
    double q3_height = (height[14] + height[15]) / 2.0;
    double q1_weight = (weight[4] + weight[5]) / 2.0;
    double q3_weight = (weight[14] + weight[15]) / 2.0;
    double iqr_height = q3_height - q1_height;
    double iqr_weight = q3_weight - q1_weight;

    std::cout << "\nFive number summary of height: " << min_height << " " << q1_height << " " << median << " " << q3_height << " " << max_height << "\n";
    std::cout << "Five number summary of weight: " << min_weight << " " << q1_weight << " " << median << " " << q3_weight << " " << max_weight << "\n";
    std::cout << "Interquantile range of height: " << iqr_height << "\n";
    std::cout << "Interquantile range of weight: " << iqr_weight << "\n";

    // Printing out x y x-mean y-mean (x-mean)^2 (y-mean)^2 (x-mean)(y-mean)
    std::cout << "\n\nx\ty\tx-mean\ty-mean\t(x-mean)^2\t(y-mean)^2\t(x-mean)(y-mean)\n";
    for (int i = 0; i < 20; i++)
    {
        std::cout << height[i] << "\t" << weight[i] << "\t" << dev_height[i] << "\t" << dev_weight[i] << "\t" << sq_dev_height[i] << "\t\t" << sq_dev_weight[i] << "\t\t" << dev_height[i] * dev_weight[i] << "\n";
    }

    double sum_dev_height_dev_weight = 0;
    for (int i = 0; i < 20; i++)
    {
        sum_dev_height_dev_weight += dev_height[i] * dev_weight[i];
    }

    // Printing out the sum of x y x-mean y-mean (x-mean)^2 (y-mean)^2 (x-mean)(y-mean)

    std::cout << "\n\nSum of x: " << sum_height << "\n";
    std::cout << "Sum of y: " << sum_weight << "\n";
    std::cout << "Sum of (x-mean)^2: " << sum_sq_dev_height << "\n";
    std::cout << "Sum of (y-mean)^2: " << sum_sq_dev_weight << "\n";
    std::cout << "Sum of (x-mean)(y-mean): " << sum_dev_height_dev_weight << "\n";


    
    // Finding out the Co Variance for height and weight
    double covar = 0;
    for (int i = 0; i < 20; i++)
    {
        covar += dev_height[i] * dev_weight[i];
    }
    covar /= 19;
    std::cout << "\nCovariance of height and weight: " << covar << "\n";

    // Finding out the correlation coefficient for height and weight
    double corr_coeff = covar / (std_dev_height * std_dev_weight);
    std::cout << "\nCorrelation coefficient of height and weight: " << corr_coeff << "\n";

    // Finding out the regression line for height and weight
    double b1 = covar / variance_height;
    double b0 = wmean - b1 * hmean;
    std::cout << "\nRegression line for height and weight: " << b0 << " + " << b1 << "x\n";

    // Finding out the Co effiecient of determination for height and weight using 1 - (SSR/SST) formula
    double SSR = 0;
    std::cout << "height weight predicted_weight residual_weight squared_residual_weight\n";
    
    for (int i = 0; i < 20; i++)
    {
        double predicted_weight =  b0 + (b1 * height[i]);
        double residual_weight = weight[i] - predicted_weight;
        
        std::cout << height[i] << " " << weight[i] << " " << predicted_weight << " " << residual_weight << " " << pow(residual_weight, 2) << "\n";
        SSR += pow((weight[i] - b0 - b1 * height[i]), 2);
    }

    std::cout << "\nSum of squared residuals for height and weight: " << SSR << "\n";
    double SST = 0;
    for (int i = 0; i < 20; i++)
    {
        SST += pow((weight[i] - wmean), 2);
    }

    std::cout << "Sum of squared total for height and weight: " << SST << "\n";

    double coeff_determination = 1 - (SSR / SST);
    std::cout << "\nCoefficient of determination for height and weight: " << coeff_determination << "\n";

    
    
}
