# Self-Organizing Map Clustering of Education Indicators in Jawa Tengah
This repository contains code and data for clustering education indicators in Jawa Tengah using the Self-Organizing Map (SOM) algorithm in C++.

# Overview
The Self-Organizing Map (SOM) is an unsupervised learning algorithm that is used to reduce the dimensionality of data while preserving the topological structure of the input data. In C++, the SOM algorithm can be implemented by defining a map of nodes, where each node represents a weight vector with the same dimensionality as the input data. The algorithm then iteratively updates the weight vectors of the nodes to better represent the input data.

During each iteration, the algorithm selects a data point from the input data and finds the node with the weight vector that is closest to the selected data point. This node is called the Best Matching Unit (BMU). The weight vectors of the BMU and its neighboring nodes are then updated to move closer to the selected data point. This process is repeated for a predefined number of iterations or until convergence.

# Data
The data used in this project is education indicators in Jawa Tengah from BPS in 2021. This includes information such as APK (Angka Partisipasi Kasar), APM (Angka Partisipasi Murni), and APM (Angka Partisipasi Murni) for primary to high school levels.

Feel free to reach out if you have any questions or suggestions!😄👋
