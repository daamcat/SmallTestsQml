import QtQuick 2.0
import QtMultimedia 5.13
import QtQml 2.10

// "Component"s are defined with their files. We use "Type"s to create "component"s.

Rectangle // Object declaration. Object of type Rectangle.
{
    // property attributes:
    width: parent.width
    height: parent.height

    // We need to be able to control the camera from outside this component. Hence we define the properties
    // of camera as alias properties:
    // With property alias we create a direct reference to an existing property.
    property alias cameraProperties: camera
    property alias aliasCameraState: camera.cameraState

    // "Camera" is a component to access device camera(s).
    Camera
    {
        // Some property attributes are read-write, and some are read-only.
        // For example we can't set cameraStatus property. It is a read-only property attribute.
        id: camera
        deviceId: QtMultimedia.availableCameras[0].deviceId

        // In state "LoadedState" the camera is loaded and ready to get active.
        // But we want initially the camera to be inactive.
        cameraState: Camera.LoadedState

        // We want to be able to take photos with the camera. Hence we set captureMode:
        captureMode: Camera.CaptureStillImage

        // To capture images:
        imageCapture {
            id: imageCaptureInCamera
            onImageCaptured: {

            }
        }
    }

    // "VideoOutput" component is used to display the stream captured by "Camera".
    VideoOutput {
        id: videoOutput
        source: camera
        anchors.fill: parent
        fillMode: VideoOutput.PreserveAspectCrop
    }


    ButtonCaptureImage {

    }
}
