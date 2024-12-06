from pykinect import nui
import numpy
import cv2

loop_flag = True
head = lhand = rhand = (0,0)
rhdist = lhdist = 0

kinect = nui.Runtime()
kinect.skeleton_engine.enabled = True

def getColorImage(frame):
    global head, lhand, rhand, lhdist, rhdist
    height, width = frame.image.height, frame.image.width  #get width and height of the images
    rgb = numpy.empty((height, width, 4), numpy.uint8)
    frame.image.copy_bits(rgb.ctypes.data)                 #copy the bit of the image to the array
    rgb = cv2.circle(rgb, tuple(map(int, head)), 5, (0,255,0),5)
    if abs(lhdist) > 0.4:
        rgb = cv2.circle(rgb, tuple(map(int, lhand)), 5, (0,0,255),5)
    else:
        rgb = cv2.circle(rgb, tuple(map(int, lhand)), 5, (0,255,0),5)
    if abs(rhdist) > 0.4:
        rgb = cv2.circle(rgb, tuple(map(int, rhand)), 5, (0,0,255),5)
    else:    
        rgb = cv2.circle(rgb, tuple(map(int, rhand)), 5, (0,255,0),5)
    
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
    global head, lhand, rhand, lhdist, rhdist
    if frame.SkeletonData is not None:
        for index, skeleton in enumerate(frame.SkeletonData):
            if skeleton.eTrackingState == nui.SkeletonTrackingState.TRACKED:
                head = nui.SkeletonEngine.skeleton_to_depth_image(skeleton.SkeletonPositions[nui.JointId.Head], 640, 480)
                lhand = nui.SkeletonEngine.skeleton_to_depth_image(skeleton.SkeletonPositions[nui.JointId.HandLeft], 640, 480)
                rhand = nui.SkeletonEngine.skeleton_to_depth_image(skeleton.SkeletonPositions[nui.JointId.HandRight], 640, 480)
                lhdist = skeleton.SkeletonPositions[nui.JointId.Head].z - skeleton.SkeletonPositions[nui.JointId.HandLeft].z
                rhdist = skeleton.SkeletonPositions[nui.JointId.Head].z - skeleton.SkeletonPositions[nui.JointId.HandRight].z
                
                
def close_all():
    global loop_flag
    loop_flag = False
    kinect.close()
    cv2.destroyAllWindows()
    

def main():
    global loop_flag
    kinect.video_frame_ready += getColorImage
    kinect.video_stream.open(nui.ImageStreamType.Video, 2, nui.ImageResolution.Resolution640x480, nui.ImageType.Color)

    #kinect.depth_frame_ready += getDepthImage
    #kinect.depth_stream.open(nui.ImageStreamType.Depth, 2, nui.ImageResolution.Resolution640x480, nui.ImageType.Depth)

    kinect.skeleton_frame_ready += frame_ready

    while loop_flag:
        continue

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        close_all()