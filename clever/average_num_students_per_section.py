import authorization
import requests
import json

class average_num_students:
	'''Calculate the average number of students per section.'''
	num_of_students = 0
	num_of_sections = 0
	rel_uri = authorization.rel_uri
	html_response = ''
	current_page = 0

	def html_response(self):
		'''Call Clever API with different relative uri'''
		request_url = ''.join([authorization.base_url, self.rel_uri])
		api_response = requests.get(request_url, headers = authorization.header)
		return api_response.text
		
	def calculate_average(self):
		'''Loop through each section and calculate sum(all students in each section) 
		and sum(all sections)'''

		while True:
			json_response = json.loads(self.html_response())
			data_array = json_response["data"]

			for data in data_array:
				self.num_of_students += len(data["data"]["students"])
				self.num_of_sections += 1
			
			links_rel_second = json_response["links"][1]["rel"]
			
			if links_rel_second == "next":
				self.rel_uri = json_response["links"][1]["uri"]
			else:
				break

if __name__ == "__main__":
	average = average_num_students()
	average.calculate_average()
	section_average = (average.num_of_students)/(average.num_of_sections)
	print "Total number of students", average.num_of_students
	print "Total number of sections", average.num_of_sections
	print "Section average is", section_average