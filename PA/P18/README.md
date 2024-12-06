# Yolo V8

# Dependencias 
pip install ultralytics

# Etiquetador Online 

roboflow


# Trainig

yolo task=detect mode=train model=yolov8s.pt data=data.yaml epochs=3 imgsz=640


Referencias:
https://medium.com/augmented-startups/train-yolov8-on-custom-data-6d28cd348262
https://thepythoncode.com/article/real-time-object-tracking-with-yolov8-opencv#google_vignette
https://docs.ultralytics.com/yolov5/tutorials/tips_for_best_training_results/
https://dataphoenix.info/a-guide-to-the-yolo-family-of-computer-vision-models/
https://dev.to/musabshakil/simplify-image-labelling-for-ml-using-roboflow-36cl

# TIPS
- Images per class. ≥ 1500 images per class recommended
- Instances per class. ≥ 10000 instances (labeled objects) per class recommended
- Image variety. Must be representative of deployed environment. For real-world use cases we recommend images from different times of day, different seasons, different weather, different lighting, different angles, different sources (scraped online, collected locally, different cameras) etc.
- Label consistency. All instances of all classes in all images must be labelled. Partial labelling will not work.
- Label accuracy. Labels must closely enclose each object. No space should exist between an object and it's bounding box. No objects should be missing a label.
- Epochs. Start with 300 epochs. If this overfits early then you can reduce epochs. If overfitting does not occur after 300 epochs, train longer, i.e. 600, 1200 etc epochs.