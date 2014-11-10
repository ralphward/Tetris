#ifndef IMAGE_MANAGER_INCLUDED
#define IMAGE_MANAGER_INCLUDED

class image_manager
{
public:
	image_manager();
	~image_manager();

private:
	image_manager( const image_manager& );
	image_manager& operator =( const image_manager& );

public:
	const sf::Image& get_image( const std::string& filename );

private:
	std::map< std::string, sf::Image > images_;
};

#endif // IMAGE_MANAGER_INCLUDED
