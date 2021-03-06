#ifndef MAPPER_H_
#define MAPPER_H_

#include <tf.h>

//#define	MINIMUM_VELODYNE_DISTANCE 0.75
#define	MINIMUM_HEIGHT_DIFFERENCE 	0.07
#define STEREO_MAPPING_SENSOR_INDEX 	10

#define NUM_VELODYNE_POINT_CLOUDS	5
#define GLOBAL_POS_QUEUE_SIZE		100


/**
  * Prototypes
  */

void mapper_merge_online_map_with_offline_map(carmen_map_server_offline_map_message *msg);
int mapper_velodyne_variable_scan(int sensor_number, carmen_velodyne_variable_scan_message *message);
int mapper_velodyne_partial_scan(carmen_velodyne_partial_scan_message *velodyne_message);
void mapper_publish_map(double timestamp);
void mapper_set_robot_pose_into_the_map(carmen_localize_ackerman_globalpos_message *globalpos_message);
void mapper_update_grid_map(carmen_point_t xt, float *zt, sensor_parameters_t *sensor_params);
void mapper_save_current_map();
void mapper_initialize(carmen_map_config_t *map_config, carmen_robot_ackerman_config_t main_car_config, int vertical_resolution);
void mapper_change_map_origin_to_another_map_block(carmen_position_t *map_origin);
void laser_calibration(carmen_position_t *map_origin);

void laser_calibration_using_map(carmen_localize_ackerman_map_t *map);

#endif /* MAPPER_H_ */
