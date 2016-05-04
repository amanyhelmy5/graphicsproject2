#include "Model.h"


Model::Model(void)
{
}

Model::Model(std::string path)
{
    set_texture(path);
}


Model::~Model(void)
{
}

void Model::set_texture(std::string path)
{
    m_texture = std::unique_ptr<Texture>( new Texture(path, 1) );
}

void Model::bind_texture()
{
    m_texture->bind();
}

void Model::initialize()
{
	

	glGenVertexArrays(1, &m_vertex_array_object_ID);
	glBindVertexArray(m_vertex_array_object_ID);

	if(vertex_data.size()>0)
	{
		glGenBuffers(1, &m_vertex_data_buffer_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertex_data_buffer_ID);
		glBufferData(GL_ARRAY_BUFFER, vertex_data.size() * sizeof(glm::vec3), &vertex_data[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

	}
	if (color_data.size() > 0)
	{
		glGenBuffers(1, &m_color_data_buffer_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_color_data_buffer_ID);
		glBufferData(GL_ARRAY_BUFFER, color_data.size() * sizeof(glm::vec3), &color_data[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	}
	if (indices_data.size()>0)
	{
		glGenBuffers(1, &m_indices_data_buffer_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indices_data_buffer_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_data.size() * sizeof(unsigned short), &indices_data[0] , GL_STATIC_DRAW);
	}
	if (UV_data.size() > 0)
	{
		glGenBuffers(1, &m_UV_data_buffer_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_UV_data_buffer_ID);
		glBufferData(GL_ARRAY_BUFFER, UV_data.size() * sizeof(glm::vec2) , &UV_data[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		//note that the number of elements = 2 because UV coords are of type vec2
		glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,0,(void*)0);
	}
	//now all the state is save in the Vertex Array Object, we only need to bind it in the drawing code (each frame).
}

void Model::draw()
{
	glBindVertexArray(m_vertex_array_object_ID);
	if (indices_data.size() > 0)
	{
        glDrawElements(GL_TRIANGLES, indices_data.size(), GL_UNSIGNED_SHORT,0);
	}
	else
	{
		//no indices provided.
		glDrawArrays(GL_TRIANGLES, 0, vertex_data.size());
	}
}

void Model::set_direction(glm::vec3 direction)
{
	m_direction = direction;
	//m_DirectionAngle = glm::atan(m_Direction.z/m_Direction.x)*1800*PI;
}

glm::vec3 Model::get_direction()
{
	return m_direction;
}

glm::vec3 Model::get_position()
{
	return m_position;
}

void Model::set_position(glm::vec3 position)
{
	m_position = position;
}

void Model::move()
{

}


void Model::clean_up()
{
	glDeleteBuffers(1, &m_vertex_data_buffer_ID);
	glDeleteBuffers(1, &m_color_data_buffer_ID);
	glDeleteBuffers(1, &m_indices_data_buffer_ID);
	glDeleteBuffers(1, &m_UV_data_buffer_ID);
	glDeleteVertexArrays(1, &m_vertex_array_object_ID); 
}

std::vector<glm::vec3>Model::get_vertices()
{
	return vertex_data;
}
