// Este código está baseado nos exemplos disponíveis no livro 
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>

GLfloat angle, fAspect;

void DesenhaEixos(void)
{
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(10.0f,0.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,10.0f,0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,10.0f);		
	glEnd();
}

float raio = 1.0f;            
// Função callback chamada para fazer o desenho
void Desenha(void)
{

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DesenhaEixos();

	/*glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
		glTranslatef(-60.0f, 0.0f, 0.0f);
		glutSolidSphere(30.0f, 10, 10);
	glPopMatrix();
	*/
	/*   DESENHA BASE  */
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, 0.0f);
		glutSolidCube(30.0f);
	glPopMatrix();


	glTranslatef(0.0f, 25.0f, 0.0f);

	glRotatef(45.0f,0.0f,0.0f,-1.0f);

	/* DESENHA PRIMEIRA BOLA */
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glutSolidSphere(10.0f, 10, 10);
	glPopMatrix();

	glTranslatef(0.0f,30.0f,0.0f);
	

	/* DESENHA PRIMEIRO QUADRADO */
	glColor3f(1.0f,0.0f,1.0f);
	glPushMatrix();
		glScalef(raio,4*raio,raio);
		glutSolidCube(10.0f);
	glPopMatrix();


	glTranslatef(0.0f,30.0f,0.0f);

	glRotatef(45.0f,0.5f,0.0f,-2.0f);

	/*  DESENHA SEGUNDA BOLA     */
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glutSolidSphere(10.0f, 10, 10);
	glPopMatrix();
		

	glTranslatef(0.0f,30.0f,0.0f);
	
	/*  DESENHA SEGUNDO QUADRADO  */
	glColor3f(1.0f,0.0f,1.0f);
	glPushMatrix();
		glScalef(raio,4*raio,raio);
		glutSolidCube(10.0f);
	glPopMatrix();

	glTranslatef(0.0f,30.0f,0.0f);

	glRotatef(45.0f,0.5f,0.0f,-2.0f);
	/* DESENHA TERCEIRA BOLA */
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glutSolidSphere(10.0f, 10, 10);
	glPopMatrix();

	glTranslatef(0.0f,15.0f,0.0f);
	//DESENHA A PALMA
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(raio,raio,raio);
		glutSolidCube(10.0f);
	glPopMatrix();

	//DESENHA A BASE DOS DEDOS 
	
	glTranslatef(0.0f,10.0f,0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();
		glScalef(2*raio,raio,raio);
		glutSolidCube(10.0f);
	glPopMatrix();	

 	//DEDO ESQUERDO
	glTranslatef(5.0f,10.0f,0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
		glScalef(0.5*raio,raio,raio);
		glutSolidCube(10.0f);
	glPopMatrix();	

 	//DEDO DIREITO 

	glTranslatef(-10.0f,0.0f,0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glScalef(0.5*raio,raio,raio);
		glutSolidCube(10.0f);
	glPopMatrix();	
	



 	/*glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, 50.0f, 0.0f);
		glutSolidTeapot(20.0f);
	glPopMatrix();
	// Desenha o teapot com a cor corrente (solid)*/

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

    angle=45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.4,500);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}


