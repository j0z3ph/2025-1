from pykinect import nui
import numpy
import cv2

loop_flag = True
kinect = nui.Runtime()
kinect.skeleton_engine.enabled = True

def getColorImage(frame):
    global rgb
    height, width = frame.image.height, frame.image.width  #get width and height of the images
    rgb = numpy.empty((height, width, 4), numpy.uint8)
    frame.image.copy_bits(rgb.ctypes.data)                 #copy the bit of the image to the array
    cv2.imshow('KINECT', rgb) # display the image
    if cv2.waitKey(1) == 27:
        close_all()

def getDepthImage(frame):
    height, width = frame.image.height, frame.image.width  #get frame height and width
    depth = numpy.empty((height, width, 1), numpy.uint8)
    arr2d = (depth >> 3) & 4095
    arr2d >>= 4
    frame.image.copy_bits(arr2d.ctypes.data)

    cv2.imshow('KINECT depth Stream', arr2d)
    if cv2.waitKey(1) == 27:
        close_all()
        
def frame_ready(frame):
    for skeleton in frame.SkeletonData:
        if skeleton.eTrackingState == nui.SkeletonTrackingState.TRACKED:
            print(skeleton.Position.x, skeleton.Position.y, skeleton.Position.z, skeleton.Position.w)

def close_all():
    global loop_flag
    loop_flag = False
    kinect.close()
    cv2.destroyAllWindows()
    

def main():
    global loop_flag
    kinect.video_frame_ready += getColorImage
    kinect.video_stream.open(nui.ImageStreamType.Video, 2, nui.ImageResolution.Resolution640x480, nui.ImageType.Color)

    kinect.depth_frame_ready += getDepthImage
    kinect.depth_stream.open(nui.ImageStreamType.Depth, 2, nui.ImageResolution.Resolution640x480, nui.ImageType.Depth)

    kinect.skeleton_frame_ready += frame_ready

    while loop_flag:
        continue

if __name__ == '__main__':
    main()