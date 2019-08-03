/*! \brief Structure for a n dimenstional dataset composed of
 *  \brief  non missing floating point values.
 */
typedef struct {
  float** values;
  int n_values; /*!< number of features in the dataset*/
  int n_dimensions; /*!< number of dimensions*/
} dataset;

/*! \brief Structure storing a single cluster to be found by
 *  \brief  clustering algorithms
 *  \brief  such as dbscan.
 */
typedef struct {
  int * members;  /*!< integer containing the number of each feature that is
		   *   part of this cluster */
  int n_members;  /*!< number of features represented in this cluster */
  int id;         /*!< unique cluster id in a set of clusters */
} cluster;

/*! \brief Structure storing multiple clusters of a dataset to be found by
 *  \brief  clustering algorithms such as dbscan.
 */
typedef struct {
  int n_clusters; /*!< number of clusters to be contained in this set */
  cluster* clusters; /*!< the clusters contained within this set */
} split_set;

/*! \brief Structure storing close or neighbor features of a
 *  \brief feature and used for
 *  \brief the internal workings of dbscan.
 */
typedef struct {
  int * members; /*!< the features in this neighbourhood */
  int n_members; /*!< number of features in this neighborhood */
} neighbors;

// typedef struct {
//   dataset ds;
//   unsigned short* U_coords;
//   unsigned short* V_coords;
// } pointcloud;

typedef struct {
  dataset ds;
  unsigned short* U;
  unsigned short* V;
  unsigned int width;
  unsigned int height;
} pointdata;

split_set dbscan(dataset ds, float epsilon, int minpts);
