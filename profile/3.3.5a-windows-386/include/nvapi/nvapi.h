#ifndef NVAPI_NVAPI_H
#define NVAPI_NVAPI_H

DECLARE_STRUCT(NvAPI_InterfaceTable);
DECLARE_ENUM(NvAPI_Status);
DECLARE_ENUM(NV_StereoRegistryProfileType);

enum NvAPI_Status {
  NVAPI_OK                          = 0,   //!< Success. Request is completed.
  NVAPI_ERROR                       = -1,  //!< Generic error
  NVAPI_LIBRARY_NOT_FOUND           = -2,  //!< NVAPI support library cannot be loaded.
  NVAPI_NO_IMPLEMENTATION           = -3,  //!< not implemented in current driver installation
  NVAPI_API_NOT_INITIALIZED         = -4,  //!< NvAPI_Initialize has not been called (successfully)
  NVAPI_INVALID_ARGUMENT            = -5,  //!< The argument/parameter value is not valid or NULL.
  NVAPI_NVIDIA_DEVICE_NOT_FOUND     = -6,  //!< No NVIDIA display driver, or NVIDIA GPU driving a display, was found.
  NVAPI_END_ENUMERATION             = -7,  //!< No more items to enumerate
  NVAPI_INVALID_HANDLE              = -8,  //!< Invalid handle
  NVAPI_INCOMPATIBLE_STRUCT_VERSION = -9,  //!< An argument's structure version is not supported
  NVAPI_HANDLE_INVALIDATED          = -10, //!< The handle is no longer valid (likely due to GPU or display re-configuration)
  NVAPI_OPENGL_CONTEXT_NOT_CURRENT  = -11, //!< No NVIDIA OpenGL context is current (but needs to be)
  NVAPI_INVALID_POINTER             = -14, //!< An invalid pointer, usually NULL, was passed as a parameter
  NVAPI_NO_GL_EXPERT                = -12, //!< OpenGL Expert is not supported by the current drivers
  NVAPI_INSTRUMENTATION_DISABLED    = -13, //!< OpenGL Expert is supported, but driver instrumentation is currently disabled
  NVAPI_NO_GL_NSIGHT                = -15, //!< OpenGL does not support Nsight

  NVAPI_EXPECTED_LOGICAL_GPU_HANDLE                  = -100, //!< Expected a logical GPU handle for one or more parameters
  NVAPI_EXPECTED_PHYSICAL_GPU_HANDLE                 = -101, //!< Expected a physical GPU handle for one or more parameters
  NVAPI_EXPECTED_DISPLAY_HANDLE                      = -102, //!< Expected an NV display handle for one or more parameters
  NVAPI_INVALID_COMBINATION                          = -103, //!< The combination of parameters is not valid.
  NVAPI_NOT_SUPPORTED                                = -104, //!< Requested feature is not supported in the selected GPU
  NVAPI_PORTID_NOT_FOUND                             = -105, //!< No port ID was found for the I2C transaction
  NVAPI_EXPECTED_UNATTACHED_DISPLAY_HANDLE           = -106, //!< Expected an unattached display handle as one of the input parameters.
  NVAPI_INVALID_PERF_LEVEL                           = -107, //!< Invalid perf level
  NVAPI_DEVICE_BUSY                                  = -108, //!< Device is busy; request not fulfilled
  NVAPI_NV_PERSIST_FILE_NOT_FOUND                    = -109, //!< NV persist file is not found
  NVAPI_PERSIST_DATA_NOT_FOUND                       = -110, //!< NV persist data is not found
  NVAPI_EXPECTED_TV_DISPLAY                          = -111, //!< Expected a TV output display
  NVAPI_EXPECTED_TV_DISPLAY_ON_DCONNECTOR            = -112, //!< Expected a TV output on the D Connector - HDTV_EIAJ4120.
  NVAPI_NO_ACTIVE_SLI_TOPOLOGY                       = -113, //!< SLI is not active on this device.
  NVAPI_SLI_RENDERING_MODE_NOTALLOWED                = -114, //!< Setup of SLI rendering mode is not possible right now.
  NVAPI_EXPECTED_DIGITAL_FLAT_PANEL                  = -115, //!< Expected a digital flat panel.
  NVAPI_ARGUMENT_EXCEED_MAX_SIZE                     = -116, //!< Argument exceeds the expected size.
  NVAPI_DEVICE_SWITCHING_NOT_ALLOWED                 = -117, //!< Inhibit is ON due to one of the flags in NV_GPU_DISPLAY_CHANGE_INHIBIT or SLI active.
  NVAPI_TESTING_CLOCKS_NOT_SUPPORTED                 = -118, //!< Testing of clocks is not supported.
  NVAPI_UNKNOWN_UNDERSCAN_CONFIG                     = -119, //!< The specified underscan config is from an unknown source (e.g. INF)
  NVAPI_TIMEOUT_RECONFIGURING_GPU_TOPO               = -120, //!< Timeout while reconfiguring GPUs
  NVAPI_DATA_NOT_FOUND                               = -121, //!< Requested data was not found
  NVAPI_EXPECTED_ANALOG_DISPLAY                      = -122, //!< Expected an analog display
  NVAPI_NO_VIDLINK                                   = -123, //!< No SLI video bridge is present
  NVAPI_REQUIRES_REBOOT                              = -124, //!< NVAPI requires a reboot for the settings to take effect
  NVAPI_INVALID_HYBRID_MODE                          = -125, //!< The function is not supported with the current Hybrid mode.
  NVAPI_MIXED_TARGET_TYPES                           = -126, //!< The target types are not all the same
  NVAPI_SYSWOW64_NOT_SUPPORTED                       = -127, //!< The function is not supported from 32-bit on a 64-bit system.
  NVAPI_IMPLICIT_SET_GPU_TOPOLOGY_CHANGE_NOT_ALLOWED = -128, //!< There is no implicit GPU topology active. Use NVAPI_SetHybridMode to change topology.
  NVAPI_REQUEST_USER_TO_CLOSE_NON_MIGRATABLE_APPS    = -129, //!< Prompt the user to close all non-migratable applications.
  NVAPI_OUT_OF_MEMORY                                = -130, //!< Could not allocate sufficient memory to complete the call.
  NVAPI_WAS_STILL_DRAWING                            = -131, //!< The previous operation that is transferring information to or from this surface is incomplete.
  NVAPI_FILE_NOT_FOUND                               = -132, //!< The file was not found.
  NVAPI_TOO_MANY_UNIQUE_STATE_OBJECTS                = -133, //!< There are too many unique instances of a particular type of state object.
  NVAPI_INVALID_CALL                                 = -134, //!< The method call is invalid. For example, a method's parameter may not be a valid pointer.
  NVAPI_D3D10_1_LIBRARY_NOT_FOUND                    = -135, //!< d3d10_1.dll cannot be loaded.
  NVAPI_FUNCTION_NOT_FOUND                           = -136, //!< Couldn't find the function in the loaded DLL.
  NVAPI_INVALID_USER_PRIVILEGE                       = -137, //!< The application will require Administrator privileges to access this API.
                                                             //!< The application can be elevated to a higher permission level by selecting "Run as Administrator".
  NVAPI_EXPECTED_NON_PRIMARY_DISPLAY_HANDLE        = -138,   //!< The handle corresponds to GDIPrimary.
  NVAPI_EXPECTED_COMPUTE_GPU_HANDLE                = -139,   //!< Setting Physx GPU requires that the GPU is compute-capable.
  NVAPI_STEREO_NOT_INITIALIZED                     = -140,   //!< The Stereo part of NVAPI failed to initialize completely. Check if the stereo driver is installed.
  NVAPI_STEREO_REGISTRY_ACCESS_FAILED              = -141,   //!< Access to stereo-related registry keys or values has failed.
  NVAPI_STEREO_REGISTRY_PROFILE_TYPE_NOT_SUPPORTED = -142,   //!< The given registry profile type is not supported.
  NVAPI_STEREO_REGISTRY_VALUE_NOT_SUPPORTED        = -143,   //!< The given registry value is not supported.
  NVAPI_STEREO_NOT_ENABLED                         = -144,   //!< Stereo is not enabled and the function needed it to execute completely.
  NVAPI_STEREO_NOT_TURNED_ON                       = -145,   //!< Stereo is not turned on and the function needed it to execute completely.
  NVAPI_STEREO_INVALID_DEVICE_INTERFACE            = -146,   //!< Invalid device interface.
  NVAPI_STEREO_PARAMETER_OUT_OF_RANGE              = -147,   //!< Separation percentage or JPEG image capture quality is out of [0-100] range.
  NVAPI_STEREO_FRUSTUM_ADJUST_MODE_NOT_SUPPORTED   = -148,   //!< The given frustum adjust mode is not supported.
  NVAPI_TOPO_NOT_POSSIBLE                          = -149,   //!< The mosaic topology is not possible given the current state of the hardware.
  NVAPI_MODE_CHANGE_FAILED                         = -150,   //!< An attempt to do a display resolution mode change has failed.
  NVAPI_D3D11_LIBRARY_NOT_FOUND                    = -151,   //!< d3d11.dll/d3d11_beta.dll cannot be loaded.
  NVAPI_INVALID_ADDRESS                            = -152,   //!< Address is outside of valid range.
  NVAPI_STRING_TOO_SMALL                           = -153,   //!< The pre-allocated string is too small to hold the result.
  NVAPI_MATCHING_DEVICE_NOT_FOUND                  = -154,   //!< The input does not match any of the available devices.
  NVAPI_DRIVER_RUNNING                             = -155,   //!< Driver is running.
  NVAPI_DRIVER_NOTRUNNING                          = -156,   //!< Driver is not running.
  NVAPI_ERROR_DRIVER_RELOAD_REQUIRED               = -157,   //!< A driver reload is required to apply these settings.
  NVAPI_SET_NOT_ALLOWED                            = -158,   //!< Intended setting is not allowed.
  NVAPI_ADVANCED_DISPLAY_TOPOLOGY_REQUIRED         = -159,   //!< Information can't be returned due to "advanced display topology".
  NVAPI_SETTING_NOT_FOUND                          = -160,   //!< Setting is not found.
  NVAPI_SETTING_SIZE_TOO_LARGE                     = -161,   //!< Setting size is too large.
  NVAPI_TOO_MANY_SETTINGS_IN_PROFILE               = -162,   //!< There are too many settings for a profile.
  NVAPI_PROFILE_NOT_FOUND                          = -163,   //!< Profile is not found.
  NVAPI_PROFILE_NAME_IN_USE                        = -164,   //!< Profile name is duplicated.
  NVAPI_PROFILE_NAME_EMPTY                         = -165,   //!< Profile name is empty.
  NVAPI_EXECUTABLE_NOT_FOUND                       = -166,   //!< Application not found in the Profile.
  NVAPI_EXECUTABLE_ALREADY_IN_USE                  = -167,   //!< Application already exists in the other profile.
  NVAPI_DATATYPE_MISMATCH                          = -168,   //!< Data Type mismatch
  NVAPI_PROFILE_REMOVED                            = -169,   //!< The profile passed as parameter has been removed and is no longer valid.
  NVAPI_UNREGISTERED_RESOURCE                      = -170,   //!< An unregistered resource was passed as a parameter.
  NVAPI_ID_OUT_OF_RANGE                            = -171,   //!< The DisplayId corresponds to a display which is not within the normal outputId range.
  NVAPI_DISPLAYCONFIG_VALIDATION_FAILED            = -172,   //!< Display topology is not valid so the driver cannot do a mode set on this configuration.
  NVAPI_DPMST_CHANGED                              = -173,   //!< Display Port Multi-Stream topology has been changed.
  NVAPI_INSUFFICIENT_BUFFER                        = -174,   //!< Input buffer is insufficient to hold the contents.
  NVAPI_ACCESS_DENIED                              = -175,   //!< No access to the caller.
  NVAPI_MOSAIC_NOT_ACTIVE                          = -176,   //!< The requested action cannot be performed without Mosaic being enabled.
  NVAPI_SHARE_RESOURCE_RELOCATED                   = -177,   //!< The surface is relocated away from video memory.
  NVAPI_REQUEST_USER_TO_DISABLE_DWM                = -178,   //!< The user should disable DWM before calling NvAPI.
  NVAPI_D3D_DEVICE_LOST                            = -179,   //!< D3D device status is D3DERR_DEVICELOST or D3DERR_DEVICENOTRESET - the user has to reset the device.
  NVAPI_INVALID_CONFIGURATION                      = -180,   //!< The requested action cannot be performed in the current state.
  NVAPI_STEREO_HANDSHAKE_NOT_DONE                  = -181,   //!< Call failed as stereo handshake not completed.
  NVAPI_EXECUTABLE_PATH_IS_AMBIGUOUS               = -182,   //!< The path provided was too short to determine the correct NVDRS_APPLICATION
  NVAPI_DEFAULT_STEREO_PROFILE_IS_NOT_DEFINED      = -183,   //!< Default stereo profile is not currently defined
  NVAPI_DEFAULT_STEREO_PROFILE_DOES_NOT_EXIST      = -184,   //!< Default stereo profile does not exist
  NVAPI_CLUSTER_ALREADY_EXISTS                     = -185,   //!< A cluster is already defined with the given configuration.
  NVAPI_DPMST_DISPLAY_ID_EXPECTED                  = -186,   //!< The input display id is not that of a multi stream enabled connector or a display device in a multi stream topology
  NVAPI_INVALID_DISPLAY_ID                         = -187,   //!< The input display id is not valid or the monitor associated to it does not support the current operation
  NVAPI_STREAM_IS_OUT_OF_SYNC                      = -188,   //!< While playing secure audio stream, stream goes out of sync
  NVAPI_INCOMPATIBLE_AUDIO_DRIVER                  = -189,   //!< Older audio driver version than required
  NVAPI_VALUE_ALREADY_SET                          = -190,   //!< Value already set, setting again not allowed.
  NVAPI_TIMEOUT                                    = -191,   //!< Requested operation timed out
  NVAPI_GPU_WORKSTATION_FEATURE_INCOMPLETE         = -192,   //!< The requested workstation feature set has incomplete driver internal allocation resources
  NVAPI_STEREO_INIT_ACTIVATION_NOT_DONE            = -193,   //!< Call failed because InitActivation was not called.
  NVAPI_SYNC_NOT_ACTIVE                            = -194,   //!< The requested action cannot be performed without Sync being enabled.
  NVAPI_SYNC_MASTER_NOT_FOUND                      = -195,   //!< The requested action cannot be performed without Sync Master being enabled.
  NVAPI_INVALID_SYNC_TOPOLOGY                      = -196,   //!< Invalid displays passed in the NV_GSYNC_DISPLAY pointer.
  NVAPI_ECID_SIGN_ALGO_UNSUPPORTED                 = -197,   //!< The specified signing algorithm is not supported. Either an incorrect value was entered or the current installed driver/hardware does not support the input value.
  NVAPI_ECID_KEY_VERIFICATION_FAILED               = -198,   //!< The encrypted public key verification has failed.
  NVAPI_FIRMWARE_OUT_OF_DATE                       = -199,   //!< The device's firmware is out of date.
  NVAPI_FIRMWARE_REVISION_NOT_SUPPORTED            = -200,   //!< The device's firmware is not supported.
  NVAPI_LICENSE_CALLER_AUTHENTICATION_FAILED       = -201,   //!< The caller is not authorized to modify the License.
  NVAPI_D3D_DEVICE_NOT_REGISTERED                  = -202,   //!< The user tried to use a deferred context without registering the device first
  NVAPI_RESOURCE_NOT_ACQUIRED                      = -203,   //!< Head or SourceId was not reserved for the VR Display before doing the Modeset or the dedicated display.
  NVAPI_TIMING_NOT_SUPPORTED                       = -204,   //!< Provided timing is not supported.
  NVAPI_HDCP_ENCRYPTION_FAILED                     = -205,   //!< HDCP Encryption Failed for the device. Would be applicable when the device is HDCP Capable.
  NVAPI_PCLK_LIMITATION_FAILED                     = -206,   //!< Provided mode is over sink device pclk limitation.
  NVAPI_NO_CONNECTOR_FOUND                         = -207,   //!< No connector on GPU found.
  NVAPI_HDCP_DISABLED                              = -208,   //!< When a non-HDCP capable HMD is connected, we would inform user by this code.
  NVAPI_API_IN_USE                                 = -209,   //!< Atleast an API is still being called
  NVAPI_NVIDIA_DISPLAY_NOT_FOUND                   = -210,   //!< No display found on Nvidia GPU(s).
  NVAPI_PRIV_SEC_VIOLATION                         = -211,   //!< Priv security violation, improper access to a secured register.
  NVAPI_INCORRECT_VENDOR                           = -212,   //!< NVAPI cannot be called by this vendor
  NVAPI_DISPLAY_IN_USE                             = -213,   //!< DirectMode Display is already in use
  NVAPI_UNSUPPORTED_CONFIG_NON_HDCP_HMD            = -214,   //!< The Config is having Non-NVidia GPU with Non-HDCP HMD connected
  NVAPI_MAX_DISPLAY_LIMIT_REACHED                  = -215,   //!< GPU's Max Display Limit has Reached
  NVAPI_INVALID_DIRECT_MODE_DISPLAY                = -216,   //!< DirectMode not Enabled on the Display
  NVAPI_GPU_IN_DEBUG_MODE                          = -217,   //!< GPU is in debug mode, OC is NOT allowed.
  NVAPI_D3D_CONTEXT_NOT_FOUND                      = -218,   //!< No NvAPI context was found for this D3D object
  NVAPI_STEREO_VERSION_MISMATCH                    = -219,   //!< there is version mismatch between stereo driver and dx driver
  NVAPI_GPU_NOT_POWERED                            = -220,   //!< GPU is not powered and so the request cannot be completed.
  NVAPI_ERROR_DRIVER_RELOAD_IN_PROGRESS            = -221,   //!< The display driver update in progress.
  NVAPI_WAIT_FOR_HW_RESOURCE                       = -222,   //!< Wait for HW resources allocation
  NVAPI_REQUIRE_FURTHER_HDCP_ACTION                = -223,   //!< operation requires further HDCP action
  NVAPI_DISPLAY_MUX_TRANSITION_FAILED              = -224,   //!< Dynamic Mux transition failure
  NVAPI_INVALID_DSC_VERSION                        = -225,   //!< Invalid DSC version
  NVAPI_INVALID_DSC_SLICECOUNT                     = -226,   //!< Invalid DSC slice count
  NVAPI_INVALID_DSC_OUTPUT_BPP                     = -227,   //!< Invalid DSC output BPP
  NVAPI_FAILED_TO_LOAD_FROM_DRIVER_STORE           = -228,   //!< There was an error while loading nvapi.dll from the driver store.
  NVAPI_NO_VULKAN                                  = -229,   //!< OpenGL does not export Vulkan fake extensions
  NVAPI_REQUEST_PENDING                            = -230,   //!< A request for NvTOPPs telemetry CData has already been made and is pending a response.
  NVAPI_RESOURCE_IN_USE                            = -231,   //!< Operation cannot be performed because the resource is in use.
  NVAPI_INVALID_IMAGE                              = -232,   //!< Device kernel image is invalid
  NVAPI_INVALID_PTX                                = -233,   //!< PTX JIT compilation failed
  NVAPI_NVLINK_UNCORRECTABLE                       = -234,   //!< Uncorrectable NVLink error was detected during the execution
  NVAPI_JIT_COMPILER_NOT_FOUND                     = -235,   //!< PTX JIT compiler library was not found.
  NVAPI_INVALID_SOURCE                             = -236,   //!< Device kernel source is invalid.
  NVAPI_ILLEGAL_INSTRUCTION                        = -237,   //!< While executing a kernel, the device encountered an illegal instruction.
  NVAPI_INVALID_PC                                 = -238,   //!< While executing a kernel, the device program counter wrapped its address space
  NVAPI_LAUNCH_FAILED                              = -239,   //!< An exception occurred on the device while executing a kernel
  NVAPI_NOT_PERMITTED                              = -240,   //!< Attempted operation is not permitted.
  NVAPI_CALLBACK_ALREADY_REGISTERED                = -241,   //!< The callback function has already been registered.
  NVAPI_CALLBACK_NOT_FOUND                         = -242,   //!< The callback function is not found or not registered.
  NVAPI_INVALID_OUTPUT_WIRE_FORMAT                 = -243,   //!< Invalid Wire Format for the VR HMD
};

enum NV_StereoRegistryProfileType {
  NVAPI_STEREO_DEFAULT_REGISTRY_PROFILE, //!< Default registry configuration profile.
  NVAPI_STEREO_DX9_REGISTRY_PROFILE,     //!< Separate registry configuration profile for a DirectX 9 executable.
  NVAPI_STEREO_DX10_REGISTRY_PROFILE     //!< Separate registry configuration profile for a DirectX 10 executable.
};

struct NvAPI_InterfaceTable {
  uintptr_t func;
  uint32_t id;
};

#endif