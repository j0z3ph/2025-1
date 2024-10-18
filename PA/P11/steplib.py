from time import sleep

class Stepper():
    def __init__(self, total_steps: int, board: any, pin_1: int, pin_2: int, pin_3: int, pin_4: int):
        """Clase que permite controlar un motor a pasos de 4 pines

        Args:
            total_steps (int): Total de pasos por revolución del motor
            board (any): Instancia de la tarjeta arduino (Pyfirmata)
            pin_1 (int): Pin Arduino donde se conecta IN1
            pin_2 (int): Pin Arduino donde se conecta IN2
            pin_3 (int): Pin Arduino donde se conecta IN3
            pin_4 (int): Pin Arduino donde se conecta IN4
        """
        self.pin_1 = board.get_pin(f'd:{pin_1}:o')
        self.pin_2 = board.get_pin(f'd:{pin_2}:o')
        self.pin_3 = board.get_pin(f'd:{pin_3}:o')
        self.pin_4 = board.get_pin(f'd:{pin_4}:o')

        self.step_number = 0 
        self.direction = 0
        self.total_steps = total_steps 
        self.step_delay = 0

    def set_speed(self, speed: int):
        """Permite establecer la velocidad del motor

        Args:
            speed (int): La nueva velocidad.
        """
        self.step_delay = (self.total_steps / (1000 * speed))
        
    def step(self, steps_to_move: int):
        """Mueve el motor una cantidad de pasos determinada

        Args:
            steps_to_move (int): Pasos que se desea mover
        """
        if steps_to_move > 0:
            self.direction = 1
        if steps_to_move < 0:
            self.direction = 0

        steps_left = abs(steps_to_move)

        while steps_left > 0:
            sleep(self.step_delay)
            if self.direction == 1:
                self.step_number += 1
                if self.step_number == self.total_steps:
                    self.step_number = 0
            else:
                if self.direction == 0:
                    self.step_number -= 1
                    if self.step_number == 0:
                        self.step_number = self.total_steps

            steps_left -= 1

            self.step_motor(self.step_number % 8)
    
    def off(self):
        self.pin_1.write(0)
        self.pin_2.write(0)
        self.pin_3.write(0)
        self.pin_4.write(0)

    def step_motor(self, step: int):
        """Envia los datos al motor para moverlo. La configuración es a medio paso.

        Args:
            this_step (int): Paso que se ejecuta a continuación
        """
        if step == 0:
            self.pin_1.write(1)
            self.pin_2.write(0)
            self.pin_3.write(0)
            self.pin_4.write(0)
        elif step == 1:
            self.pin_1.write(1)
            self.pin_2.write(1)
            self.pin_3.write(0)
            self.pin_4.write(0)
        elif step == 2:
            self.pin_1.write(0)
            self.pin_2.write(1)
            self.pin_3.write(0)
            self.pin_4.write(0)
        elif step == 3:
            self.pin_1.write(0)
            self.pin_2.write(1)
            self.pin_3.write(1)
            self.pin_4.write(0)
        elif step == 4:
            self.pin_1.write(0)
            self.pin_2.write(0)
            self.pin_3.write(1)
            self.pin_4.write(0)
        elif step == 5:
            self.pin_1.write(0)
            self.pin_2.write(0)
            self.pin_3.write(1)
            self.pin_4.write(1)
        elif step == 6:
            self.pin_1.write(0)
            self.pin_2.write(0)
            self.pin_3.write(0)
            self.pin_4.write(1)
        elif step == 7:
            self.pin_1.write(1)
            self.pin_2.write(0)
            self.pin_3.write(0)
            self.pin_4.write(1)